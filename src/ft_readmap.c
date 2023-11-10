/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:23:33 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 10:23:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_map	*ft_lstfirst_map(t_map *map)
{
	while (map)
	{
		if (!map->prev)
			return (map);
		map = map->prev;
	}
	return (map);
}

t_map	*ft_lstlast_map(t_map *map)
{
	while (map)
	{
		if (!map->next)
			return (map);
		map = map->next;
	}
	return (map);
}

t_map	*ft_newnode_map(char content)
{
	t_map	*new_node;

	new_node = (t_map *) ft_calloc(1, sizeof(t_map));
	new_node->content = content;
	new_node->dup_content = content;
	new_node->instances = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->up = NULL;
	new_node->down = NULL;
	return (new_node);
}

t_map	**ft_newline_map(t_map **head, t_map *node)
{
	t_map	*temp;

	if (!node)
		return (head);
	if (!*head)
	{
		*head = node;
		return (head);
	}
	temp = *head;
	while (temp->down)
		temp = temp->down;
	temp->down = node;
	return (&temp->down);
}

void	ft_readmap(t_map **map, int fd)
{
	int		j;
	char	*line;

	j = 0;
	line = get_next_line(fd);
	if (line)
	{
		while (line[j])
		{
			if (j == 0)
			{
				map = ft_newline_map(map, ft_newnode_map(line[j]));
				j++;
			}
			if (line[j] == '\r' || line[j] == '\n' || line[j] == '\0')
				break ;
			ft_append_next_map(map, ft_newnode_map(line[j]));
			j++;
		}
		ft_append_prev_map(map);
		free(line);
		ft_readmap(map, fd);
	}
	return ;
}
