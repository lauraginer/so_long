/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:08:07 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/22 19:48:21 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension_map(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 4 && ft_strncmp(&str[len - 4], ".ber", 4) == 0)
		return (1);
	else
	{
		perror("Error: Extension map isn't valid");
		return (-1);
	}
}

int	check_valid_char(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
			&& game->map[y][x] != 'E' && game->map[y][x] != 'P'
			&& game->map[y][x] != 'C' && game->map[y][x] != '\n')
			{
				perror("Error: Characters are wrong");
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_format(t_game *game)
{
	int	y;

	if (game->height == 0)
		return (-1);
	game->width = ft_strlen_so_long(game->map[0]);
	y = 1;
	while (y < game->height)
	{
		if (game->width != ft_strlen_so_long(game->map[y]))
		{
			perror("Error: Map isn't rectangular");
			return (-1);
		}
		y++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
		{
			perror("Error:The map isn't surrounded by walls");
			return (-1);
		}
		y++;
	}
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
		{
			perror("Error:The map isn't surrounded by walls");
			return (-1);
		}
		x++;
	}
	return (1);
}

int	check_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player++;
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == 'C')
				game->total_coins++;
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->exit != 1 || game->total_coins < 1)
	{
		perror("Error: Total items haven't been found");
		return (-1);
	}
	return (0);
}
