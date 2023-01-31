/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:25:38 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/31 18:05:22 by aaibar-h         ###   ########.fr       */
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
static size_t	ft_splitn(const char *trstr, char c)
{
	size_t	n;
	size_t	i;

	n = 1;
	i = 0;
	while (trstr[i])
		if (trstr[i++] == c)
			n++;
	return (n);
}

char	**ft_split(const char *s, char c)
{
	char	**strarr;
	char	*next;
	char	*trstr;
	char	*c_trstr;
	size_t	size;
	size_t	i;

	trstr = ft_strtrim(s, &c);
	c_trstr = trstr;
	size = ft_splitn(trstr, c);
	strarr = malloc((size + 1) * sizeof(char *));
	if (!strarr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		next = ft_strchr(trstr, c);
		if (!next)
			next = ft_strlen(trstr) + (char *) trstr;
		strarr[i++] = ft_substr(trstr, 0, next - trstr);
		trstr = next + 1;
	}
	free(c_trstr);
	strarr[i] = NULL;
	return (strarr);
}
