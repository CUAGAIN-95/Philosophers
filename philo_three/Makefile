# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhlee <yeonhlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 20:13:39 by yeonhlee          #+#    #+#              #
#    Updated: 2021/04/07 20:31:58 by yeonhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_three

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

INC		=	-I ./includes 

SRCS	=	$(addprefix ./srcs/, \
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