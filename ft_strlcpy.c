/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:46:02 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/24 17:53:52 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, int size)
{
	const int	slen = ft_strlen(src);

	if (size == 0)
		return (slen);
	ft_memcpy(dst, src, size);
	*(dst + ft_strlen(dst)) = 0;
	return (slen);
}
