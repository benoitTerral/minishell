/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:33:48 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/25 16:38:48 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_data	*ft_lstnew(int token, char **arg, int nbr_arg)
{
	t_data	*newlist;
	int		j;

	newlist = malloc(sizeof(t_data));
	if (!newlist)
		return (0);
	newlist->token = token;
	j = -1;
	newlist->data = malloc(sizeof(char *) * (nbr_arg + 1));
	if (!newlist->data)
	{
		free(newlist);
		return (0);
	}
	while (++j < nbr_arg)
		newlist->data[j] = ft_strdup(*arg++);
	newlist->data[j] = NULL;
	newlist->nbr_arg = nbr_arg;
	newlist->next = 0;
	return (newlist);
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
