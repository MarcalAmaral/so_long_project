/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:20:02 by marvin            #+#    #+#             */
/*   Updated: 2023/11/05 12:20:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	validate_map_is_rectangle(t_game *game)
{
	int		lenght;
	int		lenght_prev_line;

	game->temp = *(game->map);
	lenght = 0;
	lenght_prev_line = 0;
	while (game->temp)
	{
		if (game->temp->next == NULL)
		{
			if (lenght_prev_line == 0)
				lenght_prev_line = lenght;
			if (lenght_prev_line != lenght)
				break ;
			game->temp = ft_lstfirst_map(game->temp);
			if (game->temp->down != NULL)
				game->temp = game->temp->down;
			else
				return (TRUE);
			lenght = 0;
		}
		lenght++;
		game->temp = game->temp->next;
	}
	return (FALSE);
}

static int	ft_map_is_rectangle(t_game *game)
{
	if ((game->arr_map[0] != game->arr_map[1])
		&& validate_map_is_rectangle(game))
		return (FALSE);
	else
	{
		ft_printf("Error\n");
		ft_printf("-The map is not rectangular, please insert a rectangular map\n");
		return (TRUE);
	}
}

static int	ft_validate_tileset(t_game *game)
{
	int	xy[2];

	xy[0] = 0;
	xy[1] = 0;
	game->temp = *(game->map);
	while (xy[0] < game->arr_map[0])
	{
		if (ft_validate_tileset_while_y(game, xy))
			return (TRUE);
		game->temp = ft_lstfirst_map(game->temp);
		game->temp = game->temp->down;
		xy[1] = 0;
		xy[0]++;
	}
	return (FALSE);
}

static int	ft_validate_types(t_game *game)
{
	int	types;

	types = ft_count_types(game, 'C');
	if (types < 1)
	{
		ft_printf("Error\n-Invalid map, please make sure the map ");
		ft_printf("passed has at least one collectible.\n");
		return (TRUE);
	}
	types = ft_count_types(game, 'P');
	if (types < 1 || types > 1)
	{
		ft_printf("Error\n-Invalid map, please make sure the map ");
		ft_printf("passed has at least one player.\n");
		return (TRUE);
	}
	types = ft_count_types(game, 'E');
	if (types < 1 || types > 1)
	{
		ft_printf("Error\n-Invalid map, please make sure the passed ");
		ft_printf("map has at least one exit and only one.\n");
		return (TRUE);
	}
	return (FALSE);
}

int	validate_map(t_game *game)
{
	if (!ft_map_is_rectangle(game) && !ft_validate_tileset(game)
		&& !ft_validate_types(game))
		return (TRUE);
	else
		return (FALSE);
}
