/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:46:53 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/22 21:05:23 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Failed opening the file");
		return (-1);
	}
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	memory_map(t_game *game)
{
	int	i;

	if (game == NULL || game->height <= 0)
	{
		perror("Error: Invalid map structure");
		return (-1);
	}
	game->map = malloc((game->height + 1) * sizeof(char *));
	if (!game->map)
	{
		perror("Error: Failed allocating memory");
		return (-1);
	}
	i = 0;
	while (i <= game->height)
	{
		game->map[i] = NULL;
		i++;
	}
	return (0);
}

int	fill_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Failed opening the file");
		return (-1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
