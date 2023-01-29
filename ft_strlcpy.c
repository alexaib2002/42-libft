/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:46:02 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/29 13:00:23 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t	len = ft_clamp(0, size, ft_strlen(src) + 1);

	if (!size)
		return (ft_strlen(src));
	ft_memcpy(dst, src, len);
	*(dst + len - 1) = 0;
	return (ft_strlen(src));
}
