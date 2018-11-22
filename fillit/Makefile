# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 12:40:48 by ikovalen          #+#    #+#              #
#    Updated: 2018/11/22 13:07:25 by ikovalen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c validation.c countchars2.c map.c

OBJ = *.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	gcc $(FLAGS) -c $(SRC)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
