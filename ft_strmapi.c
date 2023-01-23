/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:20:05 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/23 12:18:40 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		c = f(i, s[i++]);
		if (c)
		{
			ptr[j] = malloc(sizeof(char));
			ptr[j++] = c;
		}
	}
	ptr[j] = malloc(sizeof(char));
	ptr[j] = 0;
	return (ptr);
}
