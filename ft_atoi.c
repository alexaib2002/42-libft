/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:56:06 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/20 12:06:57 by aaibar-h         ###   ########.fr       */
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
