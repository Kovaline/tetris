# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 13:37:03 by ikovalen          #+#    #+#              #
#    Updated: 2018/10/29 13:37:07 by ikovalen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) *.c 
	ar rc $(NAME) *.o
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)

re: fclean all	
