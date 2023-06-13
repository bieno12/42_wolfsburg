# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 18:28:41 by zh                #+#    #+#              #
#    Updated: 2022/12/22 23:05:34 by zh               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE = 	ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c		\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strnstr.c		\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 		\
		ft_strtrim.c		\
		ft_striteri.c		\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c 		\
		ft_lstnew.c		\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c		\
		ft_minmax.c		\
		ft_concat.c		\
		ft_utoa_radix.c

GNL_SOURCE =	get_next_line/get_next_line_bonus.c	\
		get_next_line/get_next_line_utils_bonus.c
		
TEMP =	conversion/conversion.c		\
		conversion/print_char.c		\
		conversion/print_decimal.c	\
		conversion/print_hexa.c		\
		conversion/print_percent.c	\
		conversion/print_pointer.c	\
		conversion/print_str.c		\
		conversion/print_unsigned.c	\
		conversion/strmanip.c		\
		parser/parse_flags.c		\
		parser/parse_length.c		\
		parser/parse_precision.c	\
		parser/parser.c			\
		parser/parse_specifier.c	\
		parser/parse_width.c		\
		ft_printf.c
FT_PRINTF_SOURCE = $(addprefix ft_printf/, $(TEMP))
OBJECTS = $(SOURCE:.c=.o) $(GNL_SOURCE:.c=.o)  $(FT_PRINTF_SOURCE:.c=.o)
# @ is archive target
# ^ is all the prerequisites
all: $(NAME) 

$(NAME): $(OBJECTS) 
	ar -crs $@ $^
	@echo "$(NAME) created!"
%.o : %.c libft.h
	@echo "compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@ 

$(SUBDIR): 
	@make -C $@ all

bonus: $(OBJECTS)
	@ar r $(NAME) $(OBJECTS)
	@echo "bonus libft created!"


clean: 
	rm -rf $(OBJECTS)
fclean: clean
	rm -f $(NAME)
%_clean: %
	make -C $< fclean

re: fclean all

.PHONY: 
