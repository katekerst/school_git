# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siolive <siolive@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 11:38:27 by siolive           #+#    #+#              #
#    Updated: 2019/07/25 15:22:30 by siolive          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = sources

FLAGS = -Wall -Wextra -Werror

SRC_NAME = libft/ft_lstmap.c libft/ft_lstiter.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c\
libft/ft_lstnew.c libft/ft_putnbr_fd.c libft/ft_putendl_fd.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c\
libft/ft_putnbr.c libft/ft_putendl.c libft/ft_putstr.c libft/ft_putchar.c libft/ft_itoa.c libft/ft_strsplit.c\
libft/ft_strtrim.c libft/ft_strjoin.c libft/ft_strsub.c libft/ft_strnequ.c libft/ft_strequ.c libft/ft_strmapi.c\
libft/ft_strmap.c libft/ft_striteri.c libft/ft_striter.c libft/ft_strclr.c libft/ft_strdel.c libft/ft_strnew.c\
libft/ft_memdel.c libft/ft_memalloc.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_isprint.c libft/ft_isascii.c\
libft/ft_isalnum.c libft/ft_isdigit.c libft/ft_isalpha.c libft/ft_strnstr.c libft/ft_strstr.c libft/ft_strrchr.c\
libft/ft_strchr.c libft/ft_strlcat.c libft/ft_strncat.c libft/ft_strcat.c libft/ft_memcmp.c libft/ft_memchr.c\
libft/ft_memmove.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_bzero.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_strcpy.c\
libft/ft_strncpy.c libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_strdup.c libft/ft_memset.c get_next_line/get_next_line.c

INCLUDES = includes/libft.h \
includes/get_next_line.h \

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = objects

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJ))
	@gcc $(FLAGS) -o $@ -c $< -I includes

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
