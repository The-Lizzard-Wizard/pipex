# include "libft/libft.h"

int main(int argc, char **argv)
{
	(void)argc;
	
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		ft_printf("is the child process %d\n", getpid());
	} else
	{
		ft_printf("is the parent process %d\n", getpid());
	}
	
	char *cmd[] = {ft_strjoin("/bin/", argv[1]), argv[2], NULL};
	execve(cmd[0], cmd, NULL);
	return (0);
}