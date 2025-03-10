/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <*******************.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:42 by gchauvet          #+#    #+#             */
/*   Updated: 2024/11/18 15:19:35 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rs;
	unsigned int	i;

	rs = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (rs == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rs[i] = f(i, s[i]);
		i++;
	}
	return (rs);
}
