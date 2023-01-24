/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:46:02 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/24 18:44:05 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t	slen = ft_strlen(src);

	if (size == 0)
		return (slen);
	ft_memcpy(dst, src, size);
	*(dst + ft_strlen(dst)) = 0;
	return (slen);
}
