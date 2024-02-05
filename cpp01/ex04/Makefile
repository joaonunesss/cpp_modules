# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 16:25:16 by jmarinho          #+#    #+#              #
#    Updated: 2024/02/05 10:46:42 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

NAME = SedIsForLosers
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
OBJS = $(SRC:.cpp=.o)
SRC = main.cpp

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	printf "$(GREEN)Executable ./$(NAME) was created.\n$(RESET)"

clean:
	@$(RM) $(OBJS)
	printf "$(YELLOW)Object files were removed.\n$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@rm modified_text.txt
	printf "$(RED)Executable ./$(NAME) and modified_file.txt was removed.\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
