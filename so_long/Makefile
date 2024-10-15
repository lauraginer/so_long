# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 18:27:08 by lginer-m          #+#    #+#              #
#    Updated: 2024/10/15 17:46:24 by lginer-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang
CFLAGS = -g -Wall -Werror -Wextra \
		#-g -fsanitize=address,undefined \
		#-Wunreachable-code -Ofast \


MLX_DIR = MLX42/build
MLX		= $(MLX_DIR)/libmlx42.a
LINK	= -ldl -lglfw -lpthread -lm -fPIE

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = -I$(LIBFT) -I$(MLX)

SRCS = src/get_next_line_utils_bonus.c src/get_next_line_bonus.c \
		src/main.c src/base_map.c src/check.c src/utils.c src/print_error.c \
		src/base_game.c 

OBJS = ${SRCS:.c=.o}

all: mlx42 libft $(NAME)
libft:
	make -C $(LIBFT_DIR)
mlx42:
	@make -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< 
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT) $(MLX) $(LINK) -o $(NAME)
	@echo "Compiling So_long..."

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re, libft, mlx42