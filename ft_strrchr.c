/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:05:53 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/16 18:12:30 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;

	f = 0;
	while (*s)
	{
		if (*s == c)
			f = (char *) s;
		s++;
	}
	return (f);
}
