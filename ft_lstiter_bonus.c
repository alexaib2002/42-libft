/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:17:24 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/27 13:20:22 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_bonus.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
}