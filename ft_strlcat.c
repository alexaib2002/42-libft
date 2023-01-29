/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:32:58 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/29 20:00:20 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*ptr;
	size_t		len;
	const int	dlen = ft_strlen(dst);

	len = ft_clamp(0, ft_strlen(src), size - ft_strlen(dst) - 1);
	ptr = dst + ft_strlen(dst);
	ft_memcpy(ptr, src, len);
	*(ptr + len) = 0;
	return (ft_clamp(0,
			dlen + ft_strlen(src), size + ft_strlen(src)));
}
