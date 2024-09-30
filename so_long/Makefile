# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 18:27:08 by lginer-m          #+#    #+#              #
#    Updated: 2024/09/30 19:52:19 by lginer-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -g -Wall -Werror -Wextra \
		#-g -fsanitize=address,undefined \
		#-Wunreachable-code -Ofast \


MLX_DIR = ./MLX42/build
MLX		= $(MLX_DIR)/libmlx42.a
LINK	= -ldl -lglfw -lpthread -lm

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = -I$(LIBFT) -I$(MLX)

SRCS = archives/get_next_line_bonus.c \
archives/main.c \


OBJS = ${SRCS:.c=.o}

all: mlx42 libft $(NAME)
libft:
	@make -C $(LIBFT_DIR)
mlx42:
	@make -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(HEADERS) $(LINK) -o $(NAME)
	@echo "Compiling So_long..."

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re, libft, mlx42