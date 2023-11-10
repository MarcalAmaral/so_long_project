/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:13:32 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/07 19:36:30 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_create_new_player_image(t_game *game)
{
	mlx_delete_texture(game->p_texture);
	mlx_delete_image(game->mlx, game->p_img);
	game->p_texture = mlx_load_png("textures/P/p_idle.png");
	game->p_img = mlx_texture_to_image(game->mlx,
			game->p_texture);
	mlx_resize_image(game->p_img, SIZE_IMG, SIZE_IMG);
	return (1);
}

int	ft_create_textures_from_png(t_game *game)
{
	game->w_texture = mlx_load_png("textures/1/wall.png");
	game->bd_texture = mlx_load_png("textures/0/ground.png");
	game->p_texture = mlx_load_png("textures/P/p_idle.png");
	game->c_texture = mlx_load_png("textures/C/coin.png");
	game->e_texture = mlx_load_png("textures/E/door.png");
	if (!game->bd_texture || !game->w_texture
		|| !game->p_texture || !game->c_texture
		|| !game->e_texture)
		return (0);
	return (1);
}

void	ft_create_img_from_texture(t_game *game)
{
	game->p_img = mlx_texture_to_image(game->mlx, game->p_texture);
	game->c_img = mlx_texture_to_image(game->mlx, game->c_texture);
	game->e_img = mlx_texture_to_image(game->mlx, game->e_texture);
	game->bd_img = mlx_texture_to_image(game->mlx, game->bd_texture);
	game->w_img = mlx_texture_to_image(game->mlx, game->w_texture);
	mlx_resize_image(game->p_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->c_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->e_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->bd_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(game->w_img, SIZE_IMG, SIZE_IMG);
}
