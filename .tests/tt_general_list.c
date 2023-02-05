/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_general_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:18:59 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/05 18:14:32 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static void	tt_print_content(char *str)
{
	ft_putendl_fd(str, 1);
}

static void	tt_delstr_content(char *str)
{
	free(str);
}

void	tt_general_list(void)
{
	t_list	*list;

	ft_putendl_fd("\n*** Testing general list functions ***", 1);
	list = ft_lstnew(ft_strdup("Hello "));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world!!")));
	ft_lstadd_front(&list, ft_lstnew(ft_strdup(";) ")));
	ft_putendl_fd("Expected nodes on the list: 3", 1);
	ft_putendl_fd("Actual nodes on the list: ", 1);
	ft_putnbr_fd(ft_lstsize(list), 1);
	ft_putchar_fd('\n', 1);
	ft_lstdelone(ft_lstlast(list), (void *) &tt_delstr_content);
	list->next->next = NULL;
	ft_lstiter(list, (void *) &tt_print_content);
	ft_lstclear(&list, (void *) &tt_delstr_content);
}

void	tt_nulled_list(void)
{
	t_list	*list;

	ft_putendl_fd("*** Testing NULL list nodes ***", 1);
	list = NULL;
	ft_lstadd_back(&list,
		ft_lstnew(ft_strdup("This should be the first node")));
	ft_lstadd_back(&list, NULL);
	ft_lstadd_back(&list,
		ft_lstnew(ft_strdup("This should be the last node")));
	ft_putendl_fd("Expected nodes on the list: 2", 1);
	ft_putendl_fd("Actual nodes on the list: ", 1);
	ft_putnbr_fd(ft_lstsize(list), 1);
	ft_putchar_fd('\n', 1);
	ft_lstiter(list, (void *) &tt_print_content);
	if (!ft_lstlast(NULL))
		ft_putendl_fd("\nslstlast handles NULL tested successfully", 1);
}

char	*tt_trimspace(char *str)
{
	return (ft_strtrim(str, " "));
}

void	tt_listmap(void)
{
	t_list	*list;
	t_list	*map_list;

	ft_putendl_fd("*** Testing map list functions ***", 1);
	list = ft_lstnew(ft_strdup("This string "));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup(" _will be    ")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("  ")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup(" _completly")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("  ")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("  _trimmed !! ")));
	map_list = ft_lstmap(list, (void *) &tt_trimspace,
			(void *) &tt_delstr_content);
	ft_lstiter(map_list, (void *) &tt_print_content);
}
