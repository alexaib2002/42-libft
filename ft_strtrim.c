/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:54:49 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/29 13:49:39 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_trimlen(const char *s1, const char *set)
{
	int		len;

	len = 0;
	while (*s1)
	{
		if (!ft_isinset(*(s1++), set))
			len++;
	}
	return (len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		i;

	str = malloc(ft_trimlen(s1, set) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
	{
		if (!ft_isinset(*s1, set))
			str[i++] = *s1;
		s1++;
	}
	str[i] = 0;
	return (str);
}
