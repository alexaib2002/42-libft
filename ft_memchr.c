/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:05:50 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/18 18:43:29 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	while (n)
	{
		if (*(unsigned char *) s == (unsigned char) c)
			return ((void *) s);
		s++;
		n--;
	}
	return (NULL);
}
