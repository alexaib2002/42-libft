/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:46:02 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/28 18:20:48 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t	slen = ft_strlen(src);

	if (size == 0 || slen == 0)
		return (slen);
	if (slen < size)
		ft_memcpy(dst, src, slen + 1);
	else
	{
		ft_memcpy(dst, src, size - 1);
		*(dst + size - 1) = 0;
	}
	return (slen);
}
