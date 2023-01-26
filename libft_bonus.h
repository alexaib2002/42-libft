/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:56:35 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/01/26 10:19:58 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H
# include "libft.h"

/****************
* List functions
**************/

/**
 * @brief Creates a new node, with its variable 'content' assigned to the given
 * 'content' argument, and its 'next' variable setted to NULL.
 * @param content Node content
 * @return The generated node
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the 'new' node to the 'lst' list's front.
 * @param lst Pointer to the first node of the list
 * @param new Pointer to a new node about to be appended to the first index
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes of a list.
 * @param lst Pointer to the first node of the list
 * @return List's node count
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of a list.
 * @param lst Pointer to the first node of the list
 * @return Last node of the list
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the 'new' node to the 'lst' list's end.
 * @param lst Pointer to the first node of the list
 * @param new Pointer to a new node about to be appended to the last index
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Frees a node referenced by 'lst', and the memory allocated for its
 * 'content' with the function 'del'.
 * @param lst Node about to be freed
 * @param del Function for freeing the content of the node
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Removed recursively every node from 'lst' to the end of the list,
 * by calling 'del' and free. At the end, the pointer 'lst' will be NULL.
 * @param lst Pointer to the first node about to be freed
 * @param del Function for freeing the content of the nodes
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content
 * of every node.
 * @param lst Pointer to the first node
 * @param f Function about to be applied for every node
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content
 * of every node, appending the said node to a new list if the function 'f' ends
 * as expected. Function 'del' is called when necessary.
 * @param lst Pointer to the first node
 * @param f Function about to be applied for every node
 * @param del Function called when 'content' removal is required for a given
 * node
 * @return Pointer to the new list. NULL when memory allocation fails.
 */
t_list	ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
