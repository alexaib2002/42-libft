/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:50:49 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/19 18:01:29 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int n)
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
