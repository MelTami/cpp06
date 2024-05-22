# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 01:18:13 by mvavasso          #+#    #+#              #
#    Updated: 2024/05/22 12:44:07 by mvavasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Serializer
SRCS	= main.cpp\
 		Serialization.cpp\
		Data.cpp
OBJS		= $(addprefix objects/, $(notdir $(SRCS:.cpp=.o)))
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
CC			= c++

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME)
	
objects:
	@mkdir -p objects

objects/%.o: %.cpp | objects
	@$(CC) $(FLAGS) -c $< -o $@

run: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean: 
		@rm -rf objects

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re