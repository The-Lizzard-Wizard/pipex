/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <*******************.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:54:15 by ********          #+#    #+#             */
/*   Updated: 2025/01/27 16:20:35 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//valgrind --trace-children=yes --track-fds=yes --leak-check=full

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

char	*find_path(char *cmd, char **envp);
void	exit_error(char *error);
int		execute(char *cmd_arg, char **envp);
void	freearray(char **array);

#endif