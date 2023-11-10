/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:34:09 by marvin            #+#    #+#             */
/*   Updated: 2023/11/06 13:34:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_flood_fill(t_game *game, t_map *node)
{
	if (node->next == NULL || node->prev == NULL
		|| node->down == NULL || node->up == NULL || node->dup_content == '1')
		return (FALSE);
	node->dup_content = '1';
	if (ft_flood_fill(game, node->next) || ft_flood_fill(game, node->prev) \
	|| ft_flood_fill(game, node->up) || ft_flood_fill(game, node->down))
	{
		return (TRUE);
	}
	return (0);
}

static int	ft_valid_route(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->temp = *(game->map);
	while (x < game->arr_map[0])
	{
		while (y < game->arr_map[1])
		{
			if (game->temp->dup_content != '1'
				&& game->temp->dup_content != '0')
				return (FALSE);
			if (game->temp->next == NULL)
				break ;
			game->temp = game->temp->next;
			y++;
		}
		game->temp = ft_lstfirst_map(game->temp);
		game->temp = game->temp->down;
		y = 0;
		x++;
	}
	return (TRUE);
}

static int	ft_valid_edges_top_buttom(t_game *game)
{
	t_map	*node;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->temp = *(game->map);
	node = game->temp;
	while (x < (game->arr_map[0] - 1))
	{
		node = node->down;
		x++;
	}
	while (y < game->arr_map[1])
	{
		if (node->content != '1' || game->temp->content != '1')
			return (FALSE);
		if (node->next == NULL)
			break ;
		node = node->next;
		game->temp = game->temp->next;
		y++;
	}
	return (TRUE);
}

static int	ft_valid_edges(t_game *game)
{
	t_map	*border_left;
	t_map	*border_right;
	int		x;

	x = 0;
	border_left = *(game->map);
	border_right = ft_lstlast_map(border_left);
	if (!ft_valid_edges_top_buttom(game))
		return (FALSE);
	while (x < game->arr_map[0])
	{
		if (border_left->content != '1' || border_right->content != '1')
			return (FALSE);
		else
		{
			border_left = border_left->down;
			border_right = border_right->down;
		}
		x++;
	}
	return (TRUE);
}

int	flood_fill_map(t_game *game)
{
	p_position(game, game->player);
	ft_flood_fill(game, game->player->p_position);
	if (!ft_valid_route(game) || !ft_valid_edges(game))
	{
		ft_printf("Error\n-Check if");
		ft_printf(" the map has a valid route and is surrounded by walls.\n");
		return (FALSE);
	}
	else
		return (TRUE);
}
