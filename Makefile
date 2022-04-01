# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 18:47:45 by aanghel           #+#    #+#              #
#    Updated: 2022/04/01 00:24:57 by aanghel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_SERVER = server

N_CLIENT = client

SRCS = ./Ft_printf/*.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(N_SERVER) $(N_CLIENT)

$(N_SERVER) :
			$(CC) $(FLAGS) server.c -o $(N_SERVER) $(SRCS)

$(N_CLIENT) :
			$(CC) $(FLAGS) client.c -o $(N_CLIENT) $(SRCS)

norm:
	norminette -R *.c

clean: 
		rm -f *.o
		rm -f $(OBJS)

fclean: clean
		rm -f $(N_SERVER) $(N_CLIENT)

re: fclean all

.PHONY : all clean fclean re