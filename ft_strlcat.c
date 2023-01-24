/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:32:58 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/24 18:43:31 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_size;
	char		*c_dst;
	const char	*c_src;
	int			size_left;

	c_dst = dst;
	c_src = src;
	dst_size = ft_strlen(dst);
	size_left = size - dst_size - 1;
	if (dst_size + 1 > size)
		return (ft_strlen(src) + size);
	while (*c_dst)
		*c_dst += 1;
	while (*c_src && size_left)
	{
		*c_dst++ = *c_src++;
		size_left -= 1;
	}
	if (size_left == 0)
		*c_dst = 0;
	return (dst_size + ft_strlen(src));
}
