# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 12:54:36 by zeyad             #+#    #+#              #
#    Updated: 2023/01/31 18:52:44 by zeyad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CC = gcc
#FLAGS = -Wall -Wextra -Werror
SOURCE = main.c server.c
LIBDIR = ../libft/
LIBS = -lft
HEADERS = server.h
OBJECTS = $(SOURCE:.c=.o)
# @ is archive target
# ^ is all the prerequisites
all: $(NAME)

$(NAME): $(OBJECTS) ../libft/libft.a
	@$(CC) $(FLAGS)  $(OBJECTS) -o $(NAME) -L$(LIBDIR) $(LIBS)
	@echo "$(NAME) created!"

../libft/libft.a: 
	make -C ../libft
%.o : %.c $(HEADERS)
	@echo "compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean fclean
