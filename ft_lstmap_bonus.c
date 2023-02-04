/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:12:54 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/04 19:40:51 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	void	*fcon;

	map = NULL;
	while (lst)
	{
		fcon = f(lst->content);
		if (!fcon)
		{
			ft_lstclear(&lst, del);
			break ;
		}
		if (!map)
			map = ft_lstnew(fcon);
		else
			ft_lstadd_back(&map, ft_lstnew(fcon));
		lst = lst->next;
	}
	return (map);
}
