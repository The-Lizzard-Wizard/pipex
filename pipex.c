#include "pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	child_proc(char **argv, char **envp, int *pipefd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return ;
	if (dup2(pipefd[1], STDOUT_FILENO) == -1 || dup2(infile, STDIN_FILENO) == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		close(infile);
		return ;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(infile);
	if (execute(argv[2], envp) == 0)
		return ;
}

void	parent_proc(char **argv, char **envp, int *pipefd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		return ;
	if (dup2(pipefd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
	{
		close(pipefd[1]);
		close(pipefd[0]);
		close(outfile);
		return ;
	}
	close(pipefd[1]);
	close(pipefd[0]);
	close(outfile);
	if (execute(argv[3], envp) == 0)
		return ;
}

int		main(int argc, char **argv, char **envp)
{
	int pid;
	int pipefd[2];

	if (argc != 5)
		return (write(2, "Bad arguments\n", 15), EXIT_FAILURE);
	if (pipe(pipefd) == -1)
		exit_error("pipe");
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		exit_error("fork");
	}
	else if (pid == 0)
		child_proc(argv, envp, pipefd);
	else
		parent_proc(argv, envp, pipefd);
	wait(&pid);
	return (0);
}
