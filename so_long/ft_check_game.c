/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:08:07 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/02 00:01:18 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_line_map(int fd)
{
	char	*line;
	int		i;

	if(fd < 0)
		return (0); //NULL
	while((line = get_next_line(fd)) != NULL)
	{
		i = 0;
		while(line[i])
		{
			if(line[i] != '1' && line[i] != '0' && line[i] != '\n' &&
			   line[i] != 'P' || line[i] != 'C' || line[i] != 'E')
			{
				free(line); //se asigna memoria por haber utilizado la funcion gnl
				return (0); //NULL
			}		
			i++;
		}
		free(line);
	}
	return (1);
}

int	ft_check_extension_map(char *str)
{
	int	len;

	len = ft_strlen(str);
	if(len > 4 && ft_strncmp(&str[len - 4], ".ber", 4) == 0)
		return(1);
	else
		return(0);
}

/*int main()
{
    char *filename = "map_0.ber";
    int fd;

    if (ft_check_extension_map(filename))
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
    }

    return (0);
}*/