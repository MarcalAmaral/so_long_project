/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:55:51 by marvin            #+#    #+#             */
/*   Updated: 2023/11/05 10:55:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free_map(t_map **head)
{
	t_map	*temp;
	t_map	*temp1;

	if (!*head)
		return ;
	temp = *head;
	*head = temp->down;
	while (temp)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	ft_free_map(head);
	return ;
}

static void	ft_freeimg(t_game *game)
{
	mlx_delete_image(game->mlx, game->bd_img);
	mlx_delete_image(game->mlx, game->w_img);
	mlx_delete_image(game->mlx, game->p_img);
	mlx_delete_image(game->mlx, game->e_img);
	mlx_delete_image(game->mlx, game->c_img);
}

static void	ft_freetextures(t_game *game)
{
	mlx_delete_texture(game->bd_texture);
	mlx_delete_texture(game->w_texture);
	mlx_delete_texture(game->p_texture);
	mlx_delete_texture(game->e_texture);
	mlx_delete_texture(game->c_texture);
}

void	ft_freegame(t_game *game)
{
	ft_freeimg(game);
	ft_freetextures(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	ft_free_map(game->map);
	free(game->map);
	free(game->arr_map);
	exit (0);
}

void	ft_freegame_unit(t_game *game)
{
	ft_free_map(game->map);
	free(game->map);
	free(game->arr_map);
	exit (0);
}
