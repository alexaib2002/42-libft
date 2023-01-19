/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:59:26 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/19 16:57:41 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	const void	*odst;

	odst = dst;
	while (n--)
	{
		*(unsigned char *) dst++ = *(unsigned char *) src++;
	}
	return ((void *) odst);
}
