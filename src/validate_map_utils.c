/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:06:48 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/09 23:16:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_validate_tileset_while_y(t_game *game, int *xy)
{
	while (xy[1] < game->arr_map[1])
	{
		if (game->temp->content != 'C' && game->temp->content != 'P'
			&& game->temp->content != '0' && game->temp->content != 'E'
			&& game->temp->content != '1')
		{
			ft_printf("Error\n -Invalid map, unrecognized character");
			ft_printf(" found in map (%c)\n", game->temp->content);
			return (TRUE);
		}
		if (game->temp->next == NULL)
			break ;
		game->temp = game->temp->next;
		xy[1]++;
	}
	return (FALSE);
}

static void	ft_while_y_count_types(t_game *game, char type, int *xyi)
{
	while (xyi[1] < game->arr_map[1])
	{
		if (game->temp->content == type)
			xyi[2]++;
		if (game->temp->next == NULL)
			break ;
		game->temp = game->temp->next;
		xyi[1]++;
	}
	return ;
}

int	ft_count_types(t_game *game, char type)
{
	int	xyi[3];

	xyi[0] = 0;
	xyi[1] = 0;
	xyi[2] = 0;
	game->temp = *(game->map);
	while (xyi[0] < game->arr_map[0])
	{
		ft_while_y_count_types(game, type, xyi);
		game->temp = ft_lstfirst_map(game->temp);
		game->temp = game->temp->down;
		xyi[1] = 0;
		xyi[0]++;
	}
	return (xyi[2]);
}
