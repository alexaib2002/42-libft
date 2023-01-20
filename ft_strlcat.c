/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:32:58 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/14 19:32:48 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int size)
{
	int			dst_size;
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
