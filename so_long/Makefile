# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 14:56:58 by zeyad             #+#    #+#              #
#    Updated: 2023/03/19 17:43:51 by zeyad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror	
SOURCE = main.c 				\
		so_long.c 				\
		color.c image.c			\
		event_handler.c			\
		player.c 				\
		map/map.c 				\
		map/map_utils.c 		\
		map/map_more_utils.c	\
		min_moves/min_moves.c	\
		min_moves/min_moves_utils.c	\
		min_moves/dfs.c 		\
		min_moves/permutation.c	

MINILIBX_DIR = minilibx_linux
MINILIBX = mlx_Linux
LIBDIR = -Llibft/ -L$(MINILIBX_DIR)
LIBS = -lft -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDE = -I./$(MINILIBX_DIR)
HEADERS = so_long.h 
OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a $(MINILIBX_DIR)/lib$(MINILIBX).a
	@$(CC) $(FLAGS)  $(OBJECTS) $(INCLUDE) $(LIBDIR) $(LIBS) -o $(NAME)
	@echo "$(NAME) created!"

libft/libft.a: 
	@make -C libft
$(MINILIBX_DIR)/lib$(MINILIBX).a:
	@make -C $(MINILIBX_DIR)
%.o : %.c $(HEADERS)
	@echo "compiling $<"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean: 
	@rm -rf $(OBJECTS)
	@make -C libft clean

fclean: 
	@rm -rf $(OBJECTS)
	rm -f $(NAME)
	@make -C libft fclean
	@make -C $(MINILIBX_DIR) clean


re: fclean all
.PHONY: clean fclean