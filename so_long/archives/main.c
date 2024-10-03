/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:11:32 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/03 14:19:51 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	game;
	int		i;
	
	if (argc == 2)
	{
		game->num_lines = count_lines(argv[1]);
		if(game->num_lines < 0)
		{
			perror("Error: Failed to count lines in the file");
			return (-1);
		}
		if(memory_map(&game) < 0)
		{
			perror("Error: Failed to allocate memory for the map");
			return (-1);
		}
		if(fill_map(&game, argv[1]) < 0) //Rellenar el mapa con el contenido del archivo
		{
			perror("Error: Failed to fill the map");
			return(-1);
		}
		print_map(&game);
		i = 0;
		while(i < game->num_lines) //Liberar la memoria asignada
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	else
		printf("Error: Invalid arguments");
	return (0);
}