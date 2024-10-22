/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:16:22 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/22 22:13:58 by lginer-m         ###   ########.fr       */
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
	write(1, "Congratulations, you win!!\n", 28);
	mlx_terminate(game->mlx);
	exit(0);
}

void	keymoves(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		unllocate_map(game);
		exit(1);
	}
	keymove_w(game);
	keymove_a(game);
	keymove_s(game);
	keymove_d(game);
	move_player(game);
}
