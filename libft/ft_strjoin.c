/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <*******************.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:27:21 by gchauvet          #+#    #+#             */
/*   Updated: 2024/11/18 16:40:51 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;

	s = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		s[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	return (s);
}
