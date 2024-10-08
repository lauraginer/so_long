/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:08:07 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/08 17:30:58 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension_map(char *str)
{
	int	len;

	len = ft_strlen(str);
	if(len > 4 && ft_strncmp(&str[len - 4], ".ber", 4) == 0)
		return(1);
	else
	{
		perror("Error: Extension map isn't valid");
		return(-1);
	}
}

int	check_valid_char(t_game *game)
{	
	int	y;
	int	x;
	
	y = 0;
	if(game->player != 1 && game->exit != 1 && game->total_coins < 1)
	{
		perror("Error: Total items haven't been found");
		return(-1);
	}
	while(y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			if(game->map[y][x] != '1' && game->map[y][x] != '0' 
			&& game->map[y][x] != '\n' && game->map[y][x] != 'P' 
			&& game->map[y][x] != 'C' && game->map[y][x] != 'E')
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
	int y;
	int width;

	if(game->height == 0)
		return(-1);
	width = ft_strlen(game->map[0]); //longitud de la primera fila
	if(width == game->height) //comprobar si es cuadrado
	{
		perror("Error: Map isn't rectangular");
		return(-1);
	}
	y = 1; 
	while (y < game->height)
	{
		if(width != ft_strlen(game->map[y]))
		{
			perror("Error: Map isn't rectangular");
			return(-1);
		}
		y++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < game->height) //comprobar el ancho horizontal (primer y último carácter de cada fila)
	{
		if(game->map[y][0] != '1' || game->[y][game->width - 1] != '1')
		{
			perror("Error:The map isn't surroended by walls");
			return (-1);
		}
		y++;
	}
	while(x < game->width)
	{
		if(game->map[0][x] != '1' || game->[y][game->height - 1][x] != '1') //comprobar el alto vertical (primer y último carácter de cada columna)
		{
			perror("Error:The map isn't surroended by walls");
			return (-1);			
		}
		x++;
	}
	return(1);
}

/*int main()
{
    char *filename = "map_0.ber";
    int fd;

    /*if (ft_check_extension_map(filename))
    {
        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            return (1);
        }

        if (ft_check_line_map(fd))
        {
            printf("El archivo %s es válido.\n", filename);
        }
        else
        {
            printf("El archivo %s no es válido.\n", filename);
        }

        close(fd);
    }
    else
    {
        printf("La extensión del archivo %s no es válida.\n", filename);
    }*/

    return (0);
}