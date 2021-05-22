# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhlee <yeonhlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 20:13:39 by yeonhlee          #+#    #+#              #
#    Updated: 2021/05/22 20:17:31 by yeonhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_three

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

INC		=	-I ./includes 

SRCS	=	$(addprefix ./srcs/, \
			main.c \
			doing.c \
			finish.c \
			forks.c \
			ft_ato.c \
			ft_check.c \
			ft_get_time.c \
			init_philo_three.c \
			message.c \
			monitoring.c \
			process.c \
			util.c \
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