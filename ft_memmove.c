/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:50:49 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/24 18:47:19 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (n == 0 || dst == src)
	{
		return (dst);
	}
	while (n--)
	{
		*(((unsigned char *) dst) + n) = *(((unsigned char *) src) + n);
	}
	return (dst);
}
