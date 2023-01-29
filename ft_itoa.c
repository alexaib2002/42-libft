/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:51:35 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/29 12:14:59 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_numdigs(int n)
{
	int	d;

	d = 1;
	while (n / 10)
	{
		n /= 10;
		d++;
	}
	return (d);
}

static char	*ft_stralloc(int n)
{
	int		strsize;

	strsize = ft_numdigs(n) + 1;
	if (n < 0)
		strsize++;
	return (malloc((strsize) * sizeof(char)));
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				z;

	str = ft_stralloc(n);
	i = 0;
	z = 1;
	while (ft_numdigs(z) < ft_numdigs(n))
		z *= 10;
	if (n < 0)
	{
		str[i++] = '-';
	}
	while (z)
	{
		str[i++] = ft_abs(n / z) + NUMS_PAD;
		n -= z * (n / z);
		z /= 10;
	}
	str[i] = 0;
	return (str);
}
