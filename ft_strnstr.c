/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:32:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/24 18:46:43 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Resets the pointers relationed with little to their original
 * values. Used when a pattern has been broken.
 * @param optr Pointer to the start of little on 'big'
 * @param little Pointer to 'little'
 * @param lptr Iterator pointer of 'little'
 */
static void	ft_lrst(const char **optr, const char **little, const char **lptr)
{
	*optr = 0;
	*lptr = *little;
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*optr;
	const char	*bptr;
	const char	*lptr;

	ft_lrst(&optr, &little, &lptr);
	bptr = big;
	if (ft_strlen(little) == 0)
		return ((char *) big);
	while (*bptr && len)
	{
		if (*bptr == *lptr)
		{
			if (!optr)
				optr = bptr;
			lptr++;
			if (!*lptr)
				return ((char *) optr);
		}
		else
			ft_lrst(&optr, &little, &lptr);
		bptr++;
		len--;
	}
	return (0);
}
