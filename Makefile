# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 18:47:45 by aanghel           #+#    #+#              #
#    Updated: 2022/03/31 19:04:42 by aanghel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = server

NAMEC = client

SRC_S = server.c ./Ft_printf/*.c

SRC_C = client.c ./Ft_printf/*.c

OBJS = ${SRC_S:.c=.o}

OBJC = ${SRC_C:.c=.o}

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

OBJS :
	$(CC) $(FLAGS) ${OBJS} -o $(NAMES)
	
OBJC :
	$(CC) $(FLAGS) ${OBJC} -o $(NAMEC)
	
all: $(NAMES) $(NAMEC)

$(NAMES) : ${OBJS}

$(NAMEC) : ${OBJC}

clean: ${RM} $(NAMES) $(NAMEC)

fclean: clean
		rm -*.o

re: all fclean 

.PHONY: re all fclean clean