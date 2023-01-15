/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:33:11 by alexaib           #+#    #+#             */
/*   Updated: 2023/01/15 11:40:12 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (i < n && r == 0)
	{
		r = *s1 - *s2;
		s1 += 1;
		s2 += 1;
		i += 1;
	}
	return (r);
}