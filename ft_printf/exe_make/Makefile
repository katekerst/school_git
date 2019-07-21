# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 12:16:12 by siolive           #+#    #+#              #
#    Updated: 2019/07/21 13:59:33 by siolive          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COMPILER = gcc $(FLAGS)
FLAGS =  -g  $(INCLUDES) # ДОБАВИТЬ ФЛАГИ!-Wall -Werror -Wextra
INCLUDES = -I $(HEADER_DIR)

SOURCE = $(addprefix $(SOURCE_DIR), $(SOURCE_LIST))
SOURCE_DIR = ./sources/
SOURCE_LIST =ft_printf.c\
				string_magic.c\
				conversations.c\
				struct_option.c\
				struct_make.c\
				itoa_base_long.c\
				floats.c\
				floats1.c\
				out_per_c.c\
				out_d_i.c\
				out_f.c\
				out_o.c\
				out_p.c\
				out_s.c\
				out_u.c\
				out_hex.c\


# Подключение хедеров
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
HEADER_DIR = ./includes
HEADER_LIST =	libprint.h\
				libft.h\

#делаем так, чтобы при вызове OBJECTS вызывались абсолютно все объекты
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

#COLORS

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
BROWN = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

# Подключение школьной либы
LIBFT_CONNECT = -L $(LIBFT_DIR) -lft
LIBFT_DIR = ./libft

all: $(NAME) $(OBJECTS_DIRECTORY)

$(NAME): $(LIBFT)
	@echo "$(NAME): $(CYAN)try to gcc libft $(RESET)"
	@cd $(LIBFT_DIR) && $(MAKE)
	@$(COMPILER)  -o $(NAME) main.c $(SOURCE) $(LIBFT_CONNECT)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCE_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(NAME):$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME):try to gcc libft"
	@cd $(LIBFT_DIR) && $(MAKE)

clean:
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@echo "$(NAME): $(RED)$(NAME) was deleted $(RESET)"
	@rm -rf $(NAME)

go:
	@make re
	@echo "\n\n\n\n"
	@./$(NAME)

leaks:
	@make re
	@echo "\n"
	@valgrind ./$(NAME) | grep lost

re: fclean all
