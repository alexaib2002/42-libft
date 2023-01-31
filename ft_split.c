/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:25:38 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/31 23:44:03 by aaibar-h         ###   ########.fr       */
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

/*
TODO
*** REMOVE ME LATER ***
TODO
Implement new function is_strempty so split may detect when new split is
required in case range is empty

Check that every split will contain a complete string before calling malloc

strchr(s, 0) == s   // checks if the NUL terminator equals the current pointer
AKA the pointer is empty!!
*/

char	**ft_split(const char *s, char c)
{
	char	**strarr;
	char	*next;
	char	*c_str;
	size_t	size;
	size_t	i;

	s = ft_strtrim(s, &c);
	c_str = (char *) s;
	size = ft_splitn(s, c);
	strarr = malloc((size + 1) * sizeof(char *));
	if (!strarr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		next = ft_strchr(s, c);
		if (!next)
			next = ft_strlen(s) + (char *) s;
		strarr[i++] = ft_substr(s, 0, next - s);
		s = next + 1;
	}
	free(c_str);
	strarr[i] = NULL;
	return (strarr);
}
