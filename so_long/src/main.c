/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:11:32 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/12 16:08:52 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game, char **argv)
{	
	game->num_lines = count_lines(argv[1]);
	if(game->num_lines < 0)
	{
		printf("Error: Failed to count lines in the file");
		return;
	}
	if(memory_map(game) < 0)
	{
		printf("Error: Failed to allocate memory for the map");
		return;
	}
	if(fill_map(game, argv[1]) < 0) //Rellenar el mapa con el contenido del archivo
	{
		printf("Error: Failed to fill the map");
		return;
	}
	if(check_extension_map(argv[1]) < 0)
	{	
		printf("Error: Extension map isn't valid");
		return;
	}
	if(check_valid_char(game) < 0)
	{
		printf("Error: Characters aren't valid");
		return;
	}	
	if(check_format(game) < 0)
	{
		printf("Error: Invalid map format");
		return;
	}
	if(check_walls(game) < 0)
	{
		printf("Error: Map isn't surroended by walls");
		return;
	}
	if(check_items(game) < 0)
	{
		printf("Error: Items haven't been found");
		return;
	}
	print_map(game);
}

void	unllocate_map(t_game *game)
{
	int	i;
	
	if(game->map)
	{
		i = 0;
		while(i < game->num_lines) //Liberar la memoria asignada
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	else
	{
		printf("Error: Failed allocate map");
		return;
	}
}

int main(int argc, char **argv)
{
	t_game	game;
	
	if (argc == 2)
	{	
		load_map(&game, argv);
		unllocate_map(&game);
	}	
	else
		printf("Error: Invalid arguments");
	return(0);
}