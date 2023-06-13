/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:40:44 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 15:44:23 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;

	if (!lst || !f || !del)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (0);
	lst = lst->next;
	current = new_lst;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->content));
		if (!(current->next))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		current = current->next;
		lst = lst->next;
	}
	current->next = 0;
	return (new_lst);
}
