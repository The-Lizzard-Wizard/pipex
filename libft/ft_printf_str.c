/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <*******************.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:53:32 by gchauvet          #+#    #+#             */
/*   Updated: 2025/01/27 13:10:33 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

int	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
