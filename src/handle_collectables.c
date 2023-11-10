/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:42 by marvin            #+#    #+#             */
/*   Updated: 2023/11/02 17:37:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_collect(t_game *game, t_map *node)
{
	if (node->content == 'C')
	{
		game->c_img->instances[node->instances].enabled = 0;
		game->remain_c -= 1;
	}
	if (game->remain_c <= 0)
		game->e_img->instances[0].enabled = 1;
	return ;
}
