/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:25:38 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/08 15:52:03 by aaibar-h         ###   ########.fr       */
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
static void	ft_fillsplit(char **strarr, const size_t size, const char *str,
	const char c)
{
	char	*next;
	size_t	i;

	i = 0;
	while (i < size && *str)
	{
		next = ft_strchr(str, c);
		if (!next)
			next = ft_strlen(str) + (char *) str;
		strarr[i++] = ft_substr(str, 0, next - str);
		if (!strarr[i - 1])
		{
			ft_free_arr((void **) strarr);
			break ;
		}
		str = next;
		while (*str == c)
			str++;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**strarr;
	char	*trstr;
	size_t	size;

	trstr = ft_strtrim(s, &c);
	if (!trstr)
		return (NULL);
	size = ft_splitn(trstr, c);
	strarr = malloc((size + 1) * sizeof(char *));
	if (!strarr)
		return (NULL);
	strarr[size] = NULL;
	ft_fillsplit(strarr, size, trstr, c);
	free(trstr);
	if (!strarr)
		return (NULL);
	return (strarr);
}
