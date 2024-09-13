# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 11:34:38 by jmarinho          #+#    #+#              #
#    Updated: 2024/09/03 11:48:04 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
OBJS = $(SRC:.cpp=.o) 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

SRC = main.cpp Bureaucrat.cpp Form.cpp

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