# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 10:24:00 by zh                #+#    #+#              #
#    Updated: 2022/12/27 16:41:21 by zeyad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -g3 -Wall -Wextra -Werror  -Wunused
SOURCE =	conversion/conversion.c		\
			conversion/print_char.c		\
			conversion/print_decimal.c	\
			conversion/print_hexa.c		\
			conversion/print_percent.c	\
			conversion/print_pointer.c	\
			conversion/print_str.c		\
			conversion/print_unsigned.c	\
			conversion/strmanip.c		\
			libft/ft_atoi.c				\
			libft/ft_bzero.c			\
			libft/ft_calloc.c			\
			libft/ft_concat.c			\
			libft/ft_isalnum.c			\
			libft/ft_isalpha.c			\
			libft/ft_isascii.c			\
			libft/ft_isdigit.c			\
			libft/ft_isprint.c			\
			libft/ft_itoa.c				\
			libft/ft_lstadd_back.c		\
			libft/ft_lstadd_front.c		\
			libft/ft_lstclear.c			\
			libft/ft_lstdelone.c		\
			libft/ft_lstiter.c			\
			libft/ft_lstlast.c			\
			libft/ft_lstmap.c			\
			libft/ft_lstnew.c			\
			libft/ft_lstsize.c			\
			libft/ft_memchr.c			\
			libft/ft_memcmp.c			\
			libft/ft_memcpy.c			\
			libft/ft_memmove.c			\
			libft/ft_memset.c			\
			libft/ft_minmax.c			\
			libft/ft_putchar_fd.c		\
			libft/ft_putendl_fd.c		\
			libft/ft_putnbr_fd.c		\
			libft/ft_putstr_fd.c		\
			libft/ft_split.c			\
			libft/ft_strchr.c			\
			libft/ft_strdup.c			\
			libft/ft_striteri.c			\
			libft/ft_strjoin.c			\
			libft/ft_strlcat.c			\
			libft/ft_strlcpy.c			\
			libft/ft_strlen.c			\
			libft/ft_strmapi.c			\
			libft/ft_strncmp.c			\
			libft/ft_strnstr.c			\
			libft/ft_strrchr.c			\
			libft/ft_strtrim.c			\
			libft/ft_substr.c			\
			libft/ft_tolower.c			\
			libft/ft_toupper.c			\
			libft/ft_utoa_radix.c		\
			libft/get_next_line_bonus.c	\
			libft/get_next_line_utils_bonus.c\
			parser/parse_flags.c		\
			parser/parse_length.c		\
			parser/parse_precision.c	\
			parser/parser.c				\
			parser/parse_specifier.c	\
			parser/parse_width.c		\
			ft_printf.c

OBJECTS = $(SOURCE:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -crs $@ $^
	@echo "$(NAME) created!"
objects/%.o: %.c libft/libft.h
	@echo "compiling $<"
	@mkdir -p objects
	@mkdir -p objects/libft
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -fr $(OBJECTS)

fclean: clean
	rm -fr $(NAME)
bonus: $(NAME)

sources:
	@echo $(SOURCE) 
