/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:53:18 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/19 14:02:18 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int	r;

	r = 0;
	while (n)
	{
		r = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (r)
			return (r);
		n--;
	}
	return (0);
}
