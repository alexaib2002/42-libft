/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:56:06 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/19 16:52:48 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char			c;
	char			s;
	unsigned int	n;

	c = 0;
	s = 1;
	n = 0;
	while (*nptr == ' ')
		nptr++;
	while (*nptr)
	{
		if (*nptr == '-' && s != -1)
			s = -1;
		else if (!ft_isdigit(*nptr))
			break ;
		else
		{
			n *= 10;
			c = *nptr - (NUMS_PAD);
			n += c;
		}
		nptr++;
	}
	return (n * s);
}
