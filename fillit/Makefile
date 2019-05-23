# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siolive <siolive@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 16:08:51 by gbellege          #+#    #+#              #
#    Updated: 2019/05/16 13:10:22 by siolive          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRC=solution.c\
	norme_func.c\
	read_and_check.c\
	mine_operation.c\
	free.c\
	

FLAGS=-Wall -Wextra -Werror

INCLUDES=fillit.h

LIB=libft

all: $(NAME)

$(NAME):
	make re -C $(LIB)
	gcc $(FLAGS) -I libft/includes -o $(NAME) main.c $(SRC) -I $(INCLUDES) -L $(LIB) -lft

clean:
	make clean -C $(LIB)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all