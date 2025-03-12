#include "pipex.h"
#include "libft/libft.h"
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	child_proc(char **argv, char **envp)
{
	char	**cmd;
	cmd = ft_split(argv[2], ' ');
	execve(find_path(cmd[0], envp), cmd, envp);
}

void	parent_proc(char **argv, char **envp)
{
	wait(NULL);
	char	**cmd;
	cmd = ft_split(argv[3], ' ');
	execve(find_path(cmd[0], envp), cmd, envp);
}

int		main(int argc, char **argv, char **envp)
{
	int pid;

	pid = fork();
	(void)argc;
	if (pid == -1)
		exit_error("fork");
	else if (pid == 0)
		child_proc(argv, envp);
	else
	{
		parent_proc(argv, envp);
	}
	wait(&pid);
	return (EXIT_SUCCESS);
}