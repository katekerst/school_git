# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siolive <siolive@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 13:40:50 by siolive           #+#    #+#              #
#    Updated: 2019/07/28 14:45:35 by siolive          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -Ilibft/includes -I.

LIB = libft

LIB.A = libft.a

SRC_PATH = sources

CH_SRC_NAME = checker/main.c checker/helpers.c checker/functions.c

NAME_C = checker

OBJ_PATH = obj

CH_OBJ_NAME = $(CH_SRC_NAME:.c=.o)

CH_SRC = $(addprefix $(SRC_PATH)/, $(CH_SRC_NAME))

CH_OBJ = $(addprefix $(OBJ_PATH)/, $(CH_OBJ_NAME))

FLAGS = -Wall -Wextra -Werror

all : library $(NAME_C)
library :
	make -C $(LIB)

$(NAME_C) : $(CH_OBJ)
	gcc -o $@ $(CH_OBJ) $(INCLUDES) $(LIB)/$(LIB.A) -g

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(CH_OBJ))
	gcc -o $@ -c $< $(INCLUDES) $(FLAGS) -g

clean :
	rm -fr $(OBJ_PATH)
	make clean -C $(LIB)

fclean : clean
	rm -f $(NAME_C)
	make fclean -C $(LIB)

re : fclean all