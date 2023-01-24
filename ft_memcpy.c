/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:59:26 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/24 18:47:10 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const void	*c_dst;

	c_dst = dst;
	while (n--)
	{
		*(unsigned char *) dst++ = *(unsigned char *) src++;
	}
	return ((void *) c_dst);
}
