/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:34:18 by zh                #+#    #+#             */
/*   Updated: 2023/01/31 15:52:57 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_tlist;

char	*get_next_line(int fd);

t_tlist	*ft_lstnw(void *content);

void	ft_lstdel(int fd, t_tlist **lst);

void	ft_lstadd_bck(t_tlist **lst, t_tlist *new);

int		ft_alloc_creat(t_tlist *lst, char **new_buffer, char **buffer, int n);

void	ft_lstclr(t_tlist **lst, void (*del)(void*));

void	*ft_mmcpy(void *dest, const void *src, size_t n);

size_t	ft_strln(const char *s);

int		create_str(char *dest, char *buffer, int n);

#endif