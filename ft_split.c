/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:25:38 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/22 18:18:00 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Gets the number of words required for the given string with character
 * sequence 'c'.
 * @param s String about to split
 * @param c Split sequence
 * @return Number of strings resulting from the split operation.
 */
static int	ft_splitn(const char *s, char *c)
{
	const char	*cnext = s;
	int			n;

	n = 1;
	while (*s)
	{
		if (*(s + 1)
			&& !ft_isinset(*(s + 1), c))
		{
			if (ft_isinset(*s, c)
				&& !ft_isinset(*cnext, c))
					n++;
			cnext = s + 1;
		}
		s++;
	}
	return (n);
}

/**
 * @brief Given a pointer to a character 's' not included on the sequence 'c',
 * finds and returns the last character that isn't contained in 'c'. This can
 * be used to obtain the limits of a split word.
 * @param s Given character
 * @param c Split sequence
 * @return Last character of the word
 */
static char	*ft_mksplit(const char *s, char *c)
{
	while (*s && !ft_isinset(*s, c))
		s++;
	return (s);
}

char	**ft_split(const char *s, char *c)
{
	char	**strarr;
	int		wordl;
	int		arrl;
	int		i;
	int		j;

	i = 0;
	arrl = ft_splitn(s, c);
	strarr = malloc((arrl + 1) * sizeof(char *));
	while (*s)
	{
		if (!ft_isinset(*s, c))
		{
			j = 0;
			wordl = ft_mksplit(s, c) - s;
			strarr[i] = malloc((wordl + 1) * sizeof(char));
			while (!ft_isinset(*s, c))
				strarr[i][j++] = *(s++);
			strarr[i++][j] = 0;
		}
		else
			s++;
	}
	strarr[i] = NULL;
	return (strarr);
}
