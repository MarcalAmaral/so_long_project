/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:56:02 by marvin            #+#    #+#             */
/*   Updated: 2023/11/02 12:56:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	p_position(t_game *game, t_player *player)
{
	player->p_x = 0;
	player->p_y = 0;
	player->p_position = *(game->map);
	while (player->p_x < game->arr_map[0])
	{
		while (player->p_y < game->arr_map[1])
		{
			if (player->p_position->content == 'P')
				return ;
			if (player->p_position->next == NULL)
			{
				player->p_position = ft_lstfirst_map(player->p_position);
				break ;
			}
			player->p_position = player->p_position->next;
			player->p_y++;
		}
		player->p_position = player->p_position->down;
		player->p_x++;
		player->p_y = 0;
	}
	return ;
}

void	ft_hook_close_window(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		ft_freegame(game);
}

void	ft_hook_player_movement(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = (t_game *) param;
	p_position(game, game->player);
	if (((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_UP))
		&& keydata.action == MLX_PRESS)
		ft_player_move_up(game);
	if (((keydata.key == MLX_KEY_S) || (keydata.key == MLX_KEY_DOWN))
		&& keydata.action == MLX_PRESS)
		ft_player_move_down(game);
	if (((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT))
		&& keydata.action == MLX_PRESS)
		ft_player_move_left(game);
	if (((keydata.key == MLX_KEY_D) || (keydata.key == MLX_KEY_RIGHT))
		&& keydata.action == MLX_PRESS)
		ft_player_move_right(game);
	return ;
}
