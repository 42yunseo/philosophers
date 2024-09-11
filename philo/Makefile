# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 23:08:13 by yunseo            #+#    #+#              #
#    Updated: 2024/08/31 17:41:24 by yunseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lpthread

SRCS = main.c \
		init.c \
		utils.c \
		thread.c \
		philo.c

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LFLAGS)

clean :
	rm -rf $(OBJS) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
