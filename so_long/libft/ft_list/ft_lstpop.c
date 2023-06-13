/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:00:39 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/19 16:43:59 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//implements

//ft_lstpop_front():removes first node
//ft_lstpop_back(void *content): add an element to the list

//front(): return first item but does not remove it
//back(): return last item but does not remove it

//empty(): returns a non-zero int if there is an element or more

//destroy(): destroy the queue and free the internal list
//all methods return zero on successful operation

void	ft_lstpop_front(t_list	**lst)
{
	t_list	*node;

	if (*lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		ft_lstdelone(*lst, free);
		*lst = NULL;
	}
	else
	{
		node = *lst;
		*lst = node->next;
		ft_lstdelone(node, free);
	}
}

void	ft_lstpop_back(t_list	**lst)
{
	t_list	*node;

	if (*lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		ft_lstdelone(*lst, free);
		*lst = NULL;
		return ;
	}
	node = *lst;
	while (node->next && node->next->next)
		node = node->next;
	ft_lstdelone(node->next, free);
	node->next = NULL;
}
