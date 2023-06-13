# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 12:54:36 by zeyad             #+#    #+#              #
#    Updated: 2023/01/31 18:56:41 by zeyad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = client server

all: $(TARGET) 
	@echo server and client created!
client: 
	@make -C client_src all
	@cp client_src/client ./client
server: 
	@make -C server_src all
	@cp server_src/server ./server

clean: 
	@make -C client_src fclean
	@make -C server_src fclean
	@make -C libft clean

fclean: clean
	rm -f $(TARGET)
	@make -C libft fclean
re: fclean all
.PHONY: clean fclean $(TARGET)
