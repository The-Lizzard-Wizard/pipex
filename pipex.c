#include "pipex.h"
#include <unistd.h>
#include <sys/types.h>

void	child_proc(int argc, char **argv, char **envp)
{

}

void	parent_proc(int argc, char **argv, char **envp)
{

}

int		main(int argc, char **argv, char **envp)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		exit_error("fork");
	else if (pid == 0)
		child_proc(argc, argv, envp);
	else if (pid == 1)
		parent_proc(argc, argv, envp);
	return (0);
}