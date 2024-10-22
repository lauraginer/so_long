/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:11:32 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/22 22:13:39 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_map(t_game *game, char **argv)
{
	game->height = count_lines(argv[1]);
	if (game->height < 0)
	{
		print_error("Error: Failed to count lines in the file", game);
	}
	if (memory_map(game) < 0)
	{
		print_error("Error: Failed to allocate memory for the map", game);
	}
	if (fill_map(game, argv[1]) < 0)
	{
		print_error("Error: Failed to fill the map", game);
	}
	if (check_extension_map(argv[1]) < 0)
	{
		print_error("Error: Extension map isn't valid", game);
	}
	if (check_valid_char(game) < 0)
	{
		print_error("Error: Characters aren't valid", game);
	}
}

void	unllocate_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map == NULL)
		return ;
	while (game->map && game->map[i])
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
	if (game->txt_coin)
		mlx_delete_texture(game->txt_coin);
	if (game->txt_exit)
		mlx_delete_texture(game->txt_exit);
	if (game->txt_floor)
		mlx_delete_texture(game->txt_floor);
	if (game->txt_player)
		mlx_delete_texture(game->txt_player);
	if (game->txt_wall)
		mlx_delete_texture(game->txt_wall);
}

static int	check_isolated(t_game *game)
{
	char	**copy;

	copy = ft_copy_map(game);
	if (!copy)
		print_error("Error: Couldn't copy map", game);
	found_player(game);
	if (game->y == -1 || game->x == -1)
	{
		free_copy(game, copy);
		print_error("Error: Player not found", game);
	}
	flood_fill(game, copy, game->y, game->x);
	if (check_ec(copy) == -1)
	{
		free_copy(game, copy);
		return (-1);
	}
	free_copy(game, copy);
	return (0);
}

static void	init_game(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->total_coins = 0;
	game->player = 0;
	game->exit = 0;
	game->wall = 0;
	game->x = 0;
	game->y = 0;
	game->map = NULL;
	game->win = NULL;
	game->count = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_game(&game);
		load_map(&game, argv);
		if (check_format(&game) < 0)
			print_error("Error: Invalid map format", &game);
		if (check_walls(&game) < 0)
			print_error("Error: Map isn't surroended by walls", &game);
		if (check_items(&game) < 0)
			print_error("Error: Items haven't been found", &game);
		if (check_isolated(&game) < 0)
			print_error("Error: Isolated item\n", &game);
		start_mlx(&game);
		mlx_terminate(game.mlx);
		unllocate_map(&game);
	}
	else
		write(1, "Error: Invalid arguments\n", 26);
	return (0);
}
