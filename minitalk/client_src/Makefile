# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 12:54:36 by zeyad             #+#    #+#              #
#    Updated: 2023/01/31 18:52:30 by zeyad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
CC = gcc
#FLAGS = -Wall -Wextra -Werror
SOURCE = main.c utils/validation.c client.c
LIBDIR = ../libft/
LIBS = -lft
HEADERS = client.h 
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
