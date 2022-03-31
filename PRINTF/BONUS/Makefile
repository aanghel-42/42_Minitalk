# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 17:15:08 by pcatapan          #+#    #+#              #
#    Updated: 2022/02/09 19:45:43 by pcatapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c		\
		ft_putnb.c		\
		ft_printf_utils.c\
		ft_put_p.c		\

SRCS_B =	ft_printf.c		\
			ft_putnb.c		\
			ft_printf_utils.c\
			ft_put_p.c		\

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}
RM = rm -f
FLAGS = -Wall -Wextra -Werror
INCS = .
LIBC = ar -rcs

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
	
$(NAME) : ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	
all: $(NAME)

bonus: $(NAME) $(OBJS_B)
	${LIBC} $(NAME) $(OBJS_B)

fclean:  clean
	$(RM) $(NAME) $(bonus)
	
clean:
	$(RM) -f $(OBJS) $(OBJS_B)
	
re: fclean all

.PHONY: all bonus clean fclean re .c.o