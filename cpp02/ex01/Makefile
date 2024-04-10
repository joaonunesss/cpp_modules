# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 11:37:33 by jmarinho          #+#    #+#              #
#    Updated: 2024/04/03 14:01:47 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
OBJS = $(SRC:.cpp=.o)
SRC = main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: