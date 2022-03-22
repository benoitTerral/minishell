/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:19:58 by bterral           #+#    #+#             */
/*   Updated: 2021/11/15 14:41:20 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (lst)
	{
		while (*lst)
		{
			next_node = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next_node;
		}
	}
	*lst = NULL;
}
