# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 14:56:58 by zeyad             #+#    #+#              #
#    Updated: 2023/02/03 13:20:29 by zeyad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex

CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE = main.c pipex.c command_path.c utils.c
LIBDIR = libft/
LIBS = -lft
HEADERS = pipex.h
OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	@$(CC) $(FLAGS)  $(OBJECTS) -o $(NAME) -L$(LIBDIR) $(LIBS)
	@echo "$(NAME) created!"

libft/libft.a: 
	make -C libft

%.o : %.c $(HEADERS)
	@echo "compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@rm -rf $(OBJECTS)
	@make -C libft clean

fclean: 
	@rm -rf $(OBJECTS)
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all
.PHONY: clean fclean