# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 14:57:25 by jmarinho          #+#    #+#              #
#    Updated: 2024/01/23 16:13:25 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

NAME = account
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
OBJS = $(SRC:.cpp=.o)
SRC = Account.cpp tests.cpp

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	printf "$(GREEN)Executable ./$(NAME) was created.\n$(RESET)"

clean:
	@$(RM) $(OBJS)
	printf "$(YELLOW)Object files were removed.\n$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	printf "$(RED)Executable ./$(NAME) was removed.\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
