# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 12:12:36 by jmarinho          #+#    #+#              #
#    Updated: 2024/09/30 14:32:14 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
OBJS = $(SRC:.cpp=.o) 
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
CXX = c++

SRC = main.cpp OtherClasses.cpp

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT::