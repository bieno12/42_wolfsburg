/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:45 by zh                #+#    #+#             */
/*   Updated: 2023/01/31 15:52:56 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	ft_lstdel(int fd, t_tlist **lst)
{
	t_tlist	*temp;
	t_tlist	*current;

	if ((*lst)->fd == fd)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->content);
		free(temp);
		return ;
	}
	current = *lst;
	while (current && current->next)
	{
		if (current->next->fd == fd)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp->content);
			free(temp);
		}
		current = current->next;
	}
}

t_tlist	*ft_lstnw(void *content)
{
	t_tlist	*new_node;

	new_node = (t_tlist *)malloc(sizeof(t_tlist));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_alloc_creat(t_tlist *lst, char **new_buffer, char **buffer, int n)
{
	*new_buffer = malloc(n + 1);
	n = create_str(*new_buffer, *buffer, n);
	while (lst && lst->next)
		lst = lst->next;
	lst->next = ft_lstnw(*new_buffer);
	return (n);
}

void	ft_lstclr(t_tlist **lst, void (*del)(void*))
{
	t_tlist	*nxt;
	t_tlist	*current;

	current = *lst;
	while (current)
	{
		nxt = current->next;
		del(current->content);
		free(current);
		current = nxt;
	}
	*lst = 0;
}

size_t	ft_strln(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
