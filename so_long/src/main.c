/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:11:32 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/09 21:19:20 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game, char **argv)
{	
	game->num_lines = count_lines(argv[1]);
	if(game->num_lines < 0)
		perror("Error: Failed to count lines in the file");
	if(memory_map(game) < 0)
		perror("Error: Failed to allocate memory for the map");
	if(fill_map(game, argv[1]) < 0) //Rellenar el mapa con el contenido del archivo
		perror("Error: Failed to fill the map");
	if(check_extension_map(argv[1]) < 0)
		perror("Error: Extension map isn't valid");
	if(check_valid_char(game) < 0)
		perror("Error: Characters aren't valid");
	if(check_format(game) < 0)
		perror("Error: Invalid map format");
	if(check_walls(game) < 0)
		perror("Error: Map isn't surroended by walls");
	if(check_items(game) < 0)
		perror("Error: Items haven't been found");
	print_map(game);
}
void	unllocate_map(t_game *game)
{
	int	i;
	
	i = 0;
	while(i < game->num_lines) //Liberar la memoria asignada
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
int main(int argc, char **argv)
{
	t_game	game;
	int		i;
	
	i = 0;
	if (argc == 2)
	{	

		load_map(&game, argv);
		unllocate_map(&game);
	}	
	else
		printf("Error: Invalid arguments");
	return(0);
}