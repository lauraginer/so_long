/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_moving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:43:57 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/22 22:19:57 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	transitable_box( t_game *game, int y, int x)
{
	if (game->map[y][x] != '1')
	{
		game->y = y;
		game->x = x;
		return (1);
	}
	return (0);
}

int	keymove_w(t_game *game)
{
	int		y;
	int		x;
	char	*number;

	y = game->y;
	x = game->x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& transitable_box(game, y - 1, x))
	{
		if (game->map[y - 1][x] == 'C')
			game->total_coins--;
		game->png_player->instances[0].y -= 128;
		game->count++;
		number = ft_itoa(game->count);
		if (!number)
			print_error("Error: Failed to allocate memory\n", game);
		write(1, "Move count: ", 13);
		write(1, number, ft_strlen(number));
		write(1, "\n", 1);
		free(number);
	}
	return (-1);
}

int	keymove_a(t_game *game)
{
	int		y;
	int		x;
	char	*number;

	y = game->y;
	x = game->x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& transitable_box(game, y, x - 1))
	{
		if (game->map[y][x - 1] == 'C')
			game->total_coins--;
		game->png_player->instances[0].x -= 128;
		game->count++;
		number = ft_itoa(game->count);
		if (!number)
			print_error("Error: Failed to allocate memory\n", game);
		write(1, "Move count: ", 13);
		write(1, number, ft_strlen(number));
		write(1, "\n", 1);
		free(number);
	}
	return (-1);
}

int	keymove_s(t_game *game)
{
	int		y;
	int		x;
	char	*number;

	y = game->y;
	x = game->x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& transitable_box(game, y + 1, x))
	{
		if (game->map[y + 1][x] == 'C')
			game->total_coins--;
		game->png_player->instances[0].y += 128;
		game->count++;
		number = ft_itoa(game->count);
		if (!number)
			print_error("Error: Failed to allocate memory\n", game);
		write(1, "Move count: ", 13);
		write(1, number, ft_strlen(number));
		write(1, "\n", 1);
		free(number);
	}
	return (-1);
}

int	keymove_d(t_game *game)
{
	int		y;
	int		x;
	char	*number;

	y = game->y;
	x = game->x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& transitable_box(game, y, x + 1))
	{
		if (game->map[y][x + 1] == 'C')
			game->total_coins--;
		game->png_player->instances[0].x += 128;
		game->count++;
		number = ft_itoa(game->count);
		if (!number)
			print_error("Error: Failed to allocate memory\n", game);
		write(1, "Move count: ", 13);
		write(1, number, ft_strlen(number));
		write(1, "\n", 1);
		free(number);
	}
	return (-1);
}
