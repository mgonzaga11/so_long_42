# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:38:48 by mgonzaga          #+#    #+#              #
#    Updated: 2023/10/16 19:58:58 by mgonzaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FILES = GNL/get_next_line.c GNL/get_next_line_utils.c ft_printf/ft_printf.c\
		ft_printf/printf_functions.c ft_printf/printf_functions_2.c init_map.c\
		print_map.c check_map.c init_game.c main.c print_images.c free_close.c

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

%.o: %.c 
	cc -g3 -Wall -Wextra -Werror  -c $< -o $@ -IGNL -Ift_printf

$(NAME): $(OBJ)
	cc -g3 -Wall -Wextra -Werror $(OBJ) -o $(NAME) -IGNL -Ift_printf -lmlx -lX11 -lXext

fclean: clean
	rm -f $(NAME)
clean: 
	rm -f $(OBJ)
v: all
	valgrind --leak-check=full --show-leak-kinds=all ./so_long $(FILE)
re: fclean all

.PHONY: all fclean clean re