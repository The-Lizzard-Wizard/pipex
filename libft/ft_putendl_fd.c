/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <*******************.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:02:24 by ********          #+#    #+#             */
/*   Updated: 2024/11/15 13:17:57 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	c;

	i = 0;
	c = '\n';
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &c, 1);
}
