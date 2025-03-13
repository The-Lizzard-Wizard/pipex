#include "pipex.h"
#include "libft/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	child_proc(char **argv, char **envp, int *pipefd)
{
	char	**cmd;

	cmd = ft_split(argv[2], ' ');
	close(pipefd[0]);
	execve(find_path(cmd[0], envp), cmd, envp);
}

void	parent_proc(char **argv, char **envp, int *pipefd)
{
	char	**cmd;

	cmd = ft_split(argv[3], ' ');
	close(pipefd[1]);
	execve(find_path(cmd[0], envp), cmd, envp);
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
	{
		parent_proc(argv, envp, pipefd);
	}
	wait(&pid);
	return (EXIT_SUCCESS);
}
