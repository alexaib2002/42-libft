/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:32:58 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/09 23:29:22 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*ptr;
	size_t			len;
	const size_t	dlen = ft_strlen(dst);

	len = ft_clamp(0, ft_strlen(src), size - dlen - 1);
	ptr = dst + dlen;
	ft_memcpy(ptr, src, len);
	*(ptr + len) = 0;
	if (size > dlen)
		size = dlen;
	return (ft_clamp(0,
			dlen + ft_strlen(src), size + ft_strlen(src)));
}
