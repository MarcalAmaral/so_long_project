/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:46:16 by marvin            #+#    #+#             */
/*   Updated: 2023/09/20 20:46:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/inc/libft.h"
# include <fcntl.h>
# define SIZE_IMG 32
# define EXIT_FAIL 1
# define EXIT_OK 0
# define TRUE 1
# define FALSE 0

typedef struct s_map {
	char			content;
	char			dup_content;
	struct s_map	*next;
	struct s_map	*prev;
	struct s_map	*up;
	struct s_map	*down;
	size_t			instances;
}	t_map;

typedef struct s_player {
	int		p_x;
	int		p_y;
	t_map	*p_position;
}	t_player;

typedef struct s_game {
	mlx_t			*mlx;
	mlx_texture_t	*w_texture;
	mlx_texture_t	*bd_texture;
	mlx_texture_t	*p_texture;
	mlx_texture_t	*e_texture;
	mlx_texture_t	*c_texture;
	mlx_image_t		*bd_img;
	mlx_image_t		*w_img;
	mlx_image_t		*p_img;
	mlx_image_t		*e_img;
	mlx_image_t		*c_img;
	t_map			**map;
	t_map			*temp;
	int				*arr_map;
	int				remain_c;
	int				n_mov;
	t_player		*player;
}	t_game;

/*Handle linked list matrix*/
t_map	*ft_newnode_map(char content);
t_map	**ft_newline_map(t_map **head, t_map *node);
t_map	*ft_lstfirst_map(t_map *map);
t_map	*ft_lstlast_map(t_map *map);
void	ft_append_down_up_map(t_map **head, int *map_arr);
void	ft_append_prev_map(t_map **head);
void	ft_append_next_map(t_map **head, t_map *node);
void	ft_readmap(t_map **map, int fd);
void	ft_free_map(t_map **head);
int		*ft_mapsize(t_map **map);

/*Handle images*/
int		ft_create_textures_from_png(t_game *game);
void	ft_create_img_from_texture(t_game *game);
int		map_construct(t_game *game);
void	draw_map(t_game *game);

/* Misc functions */
int		game_init(char *path);
int     ft_count_types(t_game *game, char type);

/* Player Movements */
void	ft_hook_player_movement(mlx_key_data_t keydata, void *param);
void	ft_hook_close_window(void *param);
void	ft_player_move_up(t_game *game);
void	ft_player_move_down(t_game *game);
void	ft_player_move_left(t_game *game);
void	ft_player_move_right(t_game *game);
int		ft_create_new_player_image(t_game *game);
void	p_position(t_game *game, t_player *player);

/* Handle collectables*/
void	ft_collect(t_game *game, t_map *node);

/*Handle free*/
void	ft_freegame(t_game *game);
void	ft_freegame_unit(t_game *game);

/* Handle errors */
int		check_args(int argc, char **argv);

/* Validate map*/
int		validate_map(t_game *game);
int		flood_fill_map(t_game *game);
int		ft_validate_tileset_while_y(t_game *game, int *xy);

#endif