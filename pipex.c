#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	child_proc(char **argv, char **envp, int *pipefd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	execute(argv[2], envp);
}

void	parent_proc(char **argv, char **envp, int *pipefd)
{
	int	outfile;

	outfile = open(argv[5], O_WRONLY);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	execute(argv[3], envp);
}

int		main(int argc, char **argv, char **envp)
{
	int pid;
	int pipefd[2];

	(void)argc;
	if (pipe(pipefd) == -1)
		exit_error("pipe");
	pid = fork();
	if (pid == -1)
		exit_error("fork");
	else if (pid == 0)
		child_proc(argv, envp, pipefd);
	else
		parent_proc(argv, envp, pipefd);
	wait(&pid);
	return (0);
}
