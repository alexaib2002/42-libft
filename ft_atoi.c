/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:56:06 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/18 18:34:45 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	const char	*strp;
	char		c;
	int			n;
	int			m;

	n = 0;
	strp = nptr;
	c = 0;
	m = 1;
	while (*strp)
	{
		n *= 10;
		if (*strp == '-' && m != -1)
		{
			m = -1;
			continue ;
		}
		else if (!ft_isdigit(*strp))
			return (0);
		c = *strp - (NUMS_PAD);
		n += c;
		strp++;
	}
	return (n * m);
}
