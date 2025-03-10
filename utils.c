#include "libft/libft.h"

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
	while (paths[i])
	{
		path_no_cmd = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_no_cmd, cmd);
		free(path_no_cmd);
		i++;
	}
}
