/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:16:22 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/18 19:09:19 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_so_long(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	win_txt(t_game *game)
{
	printf("Congratulations, you win!!\n");
	mlx_terminate(game->mlx);
	exit(0);
}

void	keymoves(struct mlx_key_data keydata, void *param)
{
	t_game *game = (t_game *)param;
	if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
	}
	keymove_w(game);
	keymove_a(game);
	keymove_s(game);
	keymove_d(game);
	move_player(game);
	
}
