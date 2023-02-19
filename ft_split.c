/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:25:38 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/19 23:29:53 by alexaib          ###   ########.fr       */
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

	if (*trstr == 0)
		return (0);
	n = 1;
	i = 0;
	while (trstr[i])
	{
		if (trstr[i] == c && trstr[ft_clamp(0, ft_strlen(trstr), i + 1)] != c)
			n++;
		i++;
	}
	return (n);
}

/**
 * @brief Fills an allocated 'strarr' by splitting 'str' string based on
 * 'c' character.
 * @param strarr Splitted strings array
 * @param str Trimmed string
 * @param c Delimiter character
 * @param size Number of splits
 */

// FIXME this was created for debugging, remove before commiting changes into main!!
static int failin = 2;
char *xft_substr(const char * s, unsigned int start, size_t len)
{
	if (!failin)
		return (NULL);
	failin--;
	return (ft_substr(s, start, len));
}

#define ft_substr(s, start, len)	xft_substr(s, start, len)
// FIXME end of debug section

static char	**ft_fillsplit(const size_t size, const char *str,
	const char c)
{
	char	*next;
	char	**strarr;
	size_t	i;

	strarr = malloc((size + 1) * sizeof(char *));
	if (!strarr)
		return (NULL);
	strarr[size] = NULL;
	i = 0;
	while (i < size && *str && strarr)
	{
		next = ft_strchr(str, c);
		if (!next)
			next = ft_strlen(str) + (char *) str;
		strarr[i++] = ft_substr(str, 0, next - str);
		if (!strarr[i - 1])
		{
			ft_free_arr((void **) strarr);
			strarr = NULL;
		}
		str = next;
		while (*str == c)
			str++;
	}
	return (strarr);
}

char	**ft_split(const char *s, char c)
{
	char	**strarr;
	char	*trstr;

	trstr = ft_strtrim(s, &c);
	if (!trstr)
		return (NULL);
	strarr = ft_fillsplit(ft_splitn(trstr, c), trstr, c);
	free(trstr);
	if (!strarr)
		return (NULL);
	return (strarr);
}
