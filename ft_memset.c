/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:07:34 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/16 18:11:10 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	const void	*ptr;

	ptr = s;
	while (n--)
	{
		*(unsigned char *)s = c;
		(unsigned char *)s++;
	}
	return ((void *) ptr);
}
