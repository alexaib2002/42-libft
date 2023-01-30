/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:25:38 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/30 18:34:27 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Counts the number of splits required for creating an array for split.
 * Allocates memory for iterating a trimmed 'str' string and freeses it
 * afterwards.
 * @param str String about to be splitted
 * @param c Delimiter character
 * @return Number of splits required
 */
static int	ft_splitn(const char *str, char c)
{
	int		n;
	int		i;
	char	*trstr;

	n = 1;
	i = 0;
	trstr = ft_strtrim(str, &c);
	while (trstr[i])
		if (trstr[i++] == c)
			n++;
	free(trstr);
	return (n);
}

char	**ft_split(const char *s, char c)
{
	char	**strarr;
	char	*next;
	int		size;
	int		i;
	int		j;

	size = ft_splitn(s, c);
	strarr = malloc(size * sizeof(char *));
	i = 0;
	while (i < size)
	{
		j = 0;
		next = ft_strchr(s, c);
		if (!next)
			next = ft_strlen(s) + (char *) s;
		strarr[i] = malloc((next - s) * sizeof(char));
		while (s < next)
			strarr[i][j++] = *(s++);
		i++;
		s++;
	}
	strarr[i] = NULL;
	return (strarr);
}
