/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:17:39 by marvin            #+#    #+#             */
/*   Updated: 2023/11/02 13:17:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	update_player_movement(t_game *game)
{
	ft_create_new_player_image(game);
	mlx_image_to_window(game->mlx, game->p_img,
		game->player->p_y * SIZE_IMG, game->player->p_x * SIZE_IMG);
	game->n_mov++;
	ft_printf("\n Number of player moves: %i \n", game->n_mov);
}

void	ft_player_move_up(t_game *game)
{
	if (game->player->p_position->up->content != '1')
	{
		game->player->p_x -= 1;
		if (game->player->p_position->up->content == 'C')
			ft_collect(game, game->player->p_position->up);
		game->player->p_position->content = '0';
		game->player->p_position->up->content = 'P';
		game->player->p_position = game->player->p_position->up;
		update_player_movement(game);
	}
	if (game->remain_c <= 0 && game->e_img->instances[0].enabled == 1)
	{
		if ((game->e_img->instances[0].x / SIZE_IMG == game->player->p_y)
			&& (game->e_img->instances[0].y / SIZE_IMG == game->player->p_x))
		{
			ft_freegame(game);
			exit(0);
		}
	}
	return ;
}

void	ft_player_move_down(t_game *game)
{
	if (game->player->p_position->down->content != '1')
	{
		game->player->p_x += 1;
		if (game->player->p_position->down->content == 'C')
			ft_collect(game, game->player->p_position->down);
		game->player->p_position->content = '0';
		game->player->p_position->down->content = 'P';
		game->player->p_position = game->player->p_position->down;
		update_player_movement(game);
	}
	if (game->remain_c <= 0 && game->e_img->instances[0].enabled == 1)
	{
		if ((game->e_img->instances[0].x / SIZE_IMG == game->player->p_y)
			&& (game->e_img->instances[0].y / SIZE_IMG == game->player->p_x))
		{
			ft_freegame(game);
			exit(0);
		}
	}
	return ;
}

void	ft_player_move_left(t_game *game)
{
	if (game->player->p_position->prev->content != '1')
	{
		game->player->p_y -= 1;
		if (game->player->p_position->prev->content == 'C')
			ft_collect(game, game->player->p_position->prev);
		game->player->p_position->content = '0';
		game->player->p_position->prev->content = 'P';
		game->player->p_position = game->player->p_position->prev;
		update_player_movement(game);
	}
	if (game->remain_c <= 0 && game->e_img->instances[0].enabled == 1)
	{
		if ((game->e_img->instances[0].x / SIZE_IMG == game->player->p_y)
			&& (game->e_img->instances[0].y / SIZE_IMG == game->player->p_x))
		{
			ft_freegame(game);
			exit(0);
		}
	}
	return ;
}

void	ft_player_move_right(t_game *game)
{
	if (game->player->p_position->next->content != '1')
	{
		game->player->p_y += 1;
		if (game->player->p_position->next->content == 'C')
			ft_collect(game, game->player->p_position->next);
		game->player->p_position->content = '0';
		game->player->p_position->next->content = 'P';
		game->player->p_position = game->player->p_position->next;
		update_player_movement(game);
	}
	if (game->remain_c <= 0 && game->e_img->instances[0].enabled == 1)
	{
		if ((game->e_img->instances[0].x / SIZE_IMG == game->player->p_y)
			&& (game->e_img->instances[0].y / SIZE_IMG == game->player->p_x))
		{
			ft_freegame(game);
			exit(0);
		}
	}
	return ;
}
