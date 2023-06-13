/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:41 by zh                #+#    #+#             */
/*   Updated: 2023/01/31 15:53:53 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//returns 0 if newline wasn't found

static char	*concat(t_tlist *lst)
{
	int		size;
	int		i;
	char	*string;
	t_tlist	*node;

	size = 0;
	node = lst;
	while (node)
	{
		size += ft_strln(node->content);
		node = node->next;
	}
	if (!size)
		return (NULL);
	string = malloc(size + 1);
	string[size] = 0;
	i = 0;
	while (lst)
	{
		size = ft_strln(lst->content);
		ft_mmcpy(string + i, lst->content, size);
		i += size;
		lst = lst->next;
	}
	return (string);
}

// void print_list(t_list *lst)
// {
// 	t_list *node = lst;
// 	printf("start\n");
// 	while(node)
// 	{
// 		printf("%s\\0\n", node->content);
// 		node = node->next;
// 	}
// 	printf("end\n");

// }

void	*ft_mmcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;

	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	while (n--)
		*dest_char++ = *src_char++;
	return (dest);
}

int	create_str(char *dest, char *buffer, int n)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (i < n)
	{
		dest[i] = buffer[i];
		if (buffer[i++] == '\n')
		{
			flag = 0;
			break ;
		}
	}
	dest[i] = 0;
	ft_mmcpy(buffer, buffer + i, n - i);
	buffer[n - i] = 0;
	return (flag);
}

static char	*get_fd_buffer(int fd, t_tlist **files_buf)
{
	if (!*files_buf)
	{
		*files_buf = ft_lstnw(malloc(BUFFER_SIZE + 1));
		(*files_buf)->fd = fd;
		(*files_buf)->content[0] = 0;
		return ((*files_buf)->content);
	}
	while ((*files_buf)->next)
	{
		if ((*files_buf)->fd == fd)
			return ((*files_buf)->content);
		files_buf = &((*files_buf)->next);
	}
	if ((*files_buf)->fd == fd)
		return ((*files_buf)->content);
	(*files_buf)->next = ft_lstnw(malloc(BUFFER_SIZE + 1));
	(*files_buf)->next->fd = fd;
	(*files_buf)->next->content[0] = 0;
	return ((*files_buf)->next->content);
}

char	*get_next_line(int fd)
{
	static t_tlist	*files_buf;
	char			*buffer;
	t_tlist			*buffers;
	char			*new_buffer;
	int				n;

	if (fd < 0)
		return (NULL);
	buffer = get_fd_buffer(fd, &files_buf);
	new_buffer = malloc(ft_strln(buffer) + 1);
	if (!create_str(new_buffer, buffer, ft_strln(buffer)))
		return (new_buffer);
	buffers = ft_lstnw(new_buffer);
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		if (!ft_alloc_creat(buffers, &new_buffer, &buffer, n))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
	}
	new_buffer = concat(buffers);
	if (!new_buffer)
		ft_lstdel(fd, &files_buf);
	ft_lstclr(&buffers, free);
	return (new_buffer);
}
