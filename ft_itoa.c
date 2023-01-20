/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:51:35 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/20 14:44:02 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_numdigs(int n)
{
	int	d;

	d = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_istralloc(int n)
{
	int		digs;
	int		exdigs;

	exdigs = 1;
	digs = ft_numdigs(n);
	if (n < 0)
	{
		n *= -1;
		exdigs++;
	}
	return (malloc((digs + exdigs) * sizeof(char)));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		d;

	str = ft_istralloc(n);
	i = 0;
	d = 1;
	while (ft_numdigs(d) < ft_numdigs(n))
		d *= 10;
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	while (d)
	{
		str[i++] = (n / d) + NUMS_PAD;
		n -= d * (n / d);
		d /= 10;
	}
	str[i] = 0;
	return (str);
}
