/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:46:53 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/14 17:43:19 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
		
int	count_lines(char *file) //contar numero de lineas
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if(fd < 0)
	{
		perror("Error: Failed opening the file");
		return(-1);
	}
	
	count = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}

	close(fd);
	return (count);
}

int	memory_map(t_game *map_struct) //crear char **map= malloc((char *)*(numlineas+1));
{
	int	i;
	
	if(map_struct == NULL || map_struct->height <= 0)
	{
		perror("Error: Invalid map structure");
		return(-1);
	}
	map_struct->map = malloc((map_struct->height + 1) * sizeof(char *));
	if(!map_struct->map)
	{
		perror("Error: Failed allocating memory");
		return (-1);
	}
	i = 0;
	while(i <= map_struct->height) //Inicializa cada puntero a NULL dentro del array de líneas del mapa
	{
		map_struct->map[i] = NULL; //Asigna NULL a cada entrada para inicializarla
		i++;
	}
	return (0);
}

int	fill_map(t_game *map_struct, char *file) //leer de nuevo el fichero y rellenar map
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if(fd < 0)
	{
		perror("Error: Failed opening the file");
		return (-1);
	}
	 i = 0;
	 while((line = get_next_line(fd)) != NULL)
	{
		map_struct->map[i] = line;
		i++;
	}
	close(fd);
	return (0);
}

void	print_map(t_game *map_struct) // mostrar el mapa
{
	int	i;
	
	i = 0;
	if(map_struct == NULL || map_struct->map == NULL)
	{
		perror("Error: Map structure or map failed");
		return;
	}
	while(i < map_struct->height)
	{
		if(map_struct->map[i] != NULL)
			printf("%s", map_struct->map[i]); //ojete, tienes que poner TU printf
		i++;
	}
}
