/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:13:39 by laraujo           #+#    #+#             */
/*   Updated: 2021/11/16 13:24:32 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_dst;
	t_list	*lst_new;

	lst_dst = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst_new = ft_lstnew((*f)(lst->content));
		if (lst_new == 0)
			ft_lstclear(&lst_dst, del);
		ft_lstadd_back(&lst_dst, lst_new);
		lst = lst->next;
	}
	return (lst_dst);
}
