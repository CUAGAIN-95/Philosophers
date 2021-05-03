# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 20:13:39 by yeonhlee          #+#    #+#              #
#    Updated: 2021/04/28 17:38:08 by yeonhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_one

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

INC		=	-I ./includes 

SRCS	=	$(addprefix ./srcs/, \
			main.c \
			free/ft_free.c \
			free/ft_destroy.c \
			function/doing.c \
			function/monitoring.c \
			init/init_data.c \
			init/init_mutex.c \
			init/init_philo.c \
			print/ft_print_do.c \
			util/ft_atoi.c \
			util/ft_strlen.c \
			util/ft_get_time.c \
			)

OBJS	=	$(SRCS:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)
			
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean all

.PHONY:		all clean fclean re