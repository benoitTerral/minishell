/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:48 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/31 19:16:31 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_data	*ft_lstnew(int token, char **arg, int nbr_arg)
{
	t_data	*newlist;

	newlist = malloc(sizeof(t_data));
	if (!newlist)
		return (0);
	newlist->token = token;
	if (strdup_token(token, arg, nbr_arg, &newlist))
	{
		free(newlist);
		return (0);
	}
	newlist->next = 0;
	return (newlist);
}

t_data	*ft_lstlast(t_data *lst)
{	
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_data **alst, t_data *new)
{
	t_data	*lst;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	lst = ft_lstlast(*alst);
	lst->next = new;
}

void	ft_lstclear(t_data **lst)
{
	t_data	*tmplst;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmplst = (*lst)->next;
		ft_free_split((*lst)->data);
		free(*lst);
		*lst = tmplst;
	}
	lst = 0;
}
