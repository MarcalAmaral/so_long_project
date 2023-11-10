/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:19 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/09 20:10:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_draw_ground(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->arr_map[1])
	{
		while (x < game->arr_map[0])
		{
			mlx_image_to_window(game->mlx, game->bd_img,
				y * SIZE_IMG, x * SIZE_IMG);
			x++;
		}
		y++;
		x = 0;
	}
}

static void	ft_draw_y(t_game *game, mlx_image_t *img, char type, int *xy)
{
	while (xy[1] < game->arr_map[1])
	{
		if (game->temp->content == type)
		{
			mlx_image_to_window(game->mlx, img, xy[1] \
			* SIZE_IMG, xy[0] * SIZE_IMG);
			game->temp->instances = xy[2];
			xy[2]++;
		}
		if (game->temp->next == NULL)
			break ;
		if (game->temp->content == 'E' && type == 'E')
			game->e_img->instances[game->temp->instances].enabled = 0;
		game->temp = game->temp->next;
		xy[1]++;
	}
	return ;
}

static void	ft_draw(t_game *game, mlx_image_t *img, char type)
{
	int		x_y[3];

	x_y[0] = 0;
	x_y[1] = 0;
	x_y[2] = 0;
	game->temp = *(game->map);
	while (x_y[0] < game->arr_map[0])
	{
		ft_draw_y(game, img, type, x_y);
		game->temp = ft_lstfirst_map(game->temp);
		game->temp = game->temp->down;
		x_y[1] = 0;
		x_y[0]++;
	}
}

void	draw_map(t_game *game)
{
	ft_draw_ground(game);
	ft_draw(game, game->w_img, '1');
	ft_draw(game, game->c_img, 'C');
	ft_draw(game, game->p_img, 'P');
	ft_draw(game, game->e_img, 'E');
	return ;
}

int	map_construct(t_game *game)
{
	if (ft_create_textures_from_png(game))
	{
		ft_create_img_from_texture(game);
		return (TRUE);
	}
	else
		return (FALSE);
}
