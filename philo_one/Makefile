# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 20:13:39 by yeonhlee          #+#    #+#              #
#    Updated: 2021/05/16 10:47:45 by yeonhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_one

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

INC		=	-I ./includes 

SRCS	=	$(addprefix ./srcs/, \
			main.c \
			doing.c \
			finish.c \
			fork.c \
			ft_ato.c \
			ft_check.c \
			ft_get_time.c \
			ft_print_do.c \
			init_philo_one.c \
			monitoring.c \
			threads.c \
			util.c \
			)

OBJS	=	$(SRCS:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			clear

all:		$(NAME)
			
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean all

.PHONY:		all clean fclean re