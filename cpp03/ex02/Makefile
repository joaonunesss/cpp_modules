# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 14:10:47 by jmarinho          #+#    #+#              #
#    Updated: 2024/04/08 17:31:04 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

NAME = a.out
OBJS = $(SRC:.cpp=.o)
FLAGS = -Wextra -Wall -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)
	printf "$(GREEN)Executable ./$(NAME) was created.\n$(RESET)"

clean:
	rm -f *.o
	printf "$(YELLOW)Object files were removed.\n$(RESET)"

fclean: clean
	rm -f $(NAME)
	printf "$(RED)Executable ./$(NAME) was removed.\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
