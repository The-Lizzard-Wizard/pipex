#include "libft/libft.h"
#include <unistd.h>

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_no_cmd;
	char	*path;
	size_t	i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_no_cmd = ft_strjoin(paths[i], "/");
		if (!path_no_cmd)
			return (NULL);
		path = ft_strjoin(path_no_cmd, cmd);
		if (!path)
			return (NULL); //pute
		free(path_no_cmd);
		if (access(path, X_OK) == 0)
		{
			return (path);
		}
		i++;
	}
	return (NULL);
}

int	execute(char **argv, char **envp)
{
	
}

void	exit_error(char *error)
{
	perror(error);
	exit(0);
}
