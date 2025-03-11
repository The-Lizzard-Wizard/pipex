# include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	char **args = ft_split(argv[2], ' ');
	execve(find_path(argv[1], envp), args, envp);
	return (0);
}