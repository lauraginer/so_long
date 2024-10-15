/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:11:32 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/15 20:57:32 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_map(t_game *game, char **argv)
{	
	game->height = count_lines(argv[1]);
	if(game->height < 0)
	{
		print_error("Error: Failed to count lines in the file");
	}
	if(memory_map(game) < 0)
	{
		print_error("Error: Failed to allocate memory for the map");
	}
	if(fill_map(game, argv[1]) < 0) //Rellenar el mapa con el contenido del archivo
	{
		print_error("Error: Failed to fill the map");
	}
	if(check_extension_map(argv[1]) < 0)
	{	
		print_error("Error: Extension map isn't valid");
	}
	if(check_valid_char(game) < 0)
	{
		print_error("Error: Characters aren't valid");
	}	
}

static void	unllocate_map(t_game *game)
{
	int	i;
	
	if(game->map)
	{
		i = 0;
		while(i < game->height) //Liberar la memoria asignada
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	else
		print_error("Error: Failed allocate map");

}

static void init_game(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->coins = 0;
	game->player = 0;
	game->exit = 0;
	game->wall = 0;
	game->x = 0;
	game->y = 0;
	game->map = NULL;
	game->duplicate = NULL;
	game->win = NULL;
}

int main(int argc, char **argv) //Recuerda liberar memoria cada vez que utilices cada funcion para evitar los leaks
{
	t_game	game;
	
	if (argc == 2)
	{
		init_game(&game);
		load_map(&game, argv);
		if(check_format(&game) < 0)
			print_error("Error: Invalid map format");
		if(check_walls(&game) < 0)
			print_error("Error: Map isn't surroended by walls");
		if(check_items(&game) < 0)
			print_error("Error: Items haven't been found");
		if (flood_fill(&game) < 0)
			print_error("Error: Isolated item");
		print_map(&game);
		start_mlx(&game);
		mlx_loop(game.mlx);
		unllocate_map(&game);
		
	}	
	else
		printf("Error: Invalid arguments");
	return(0);
}