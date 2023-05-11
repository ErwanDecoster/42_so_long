/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:54:58 by edecoste          #+#    #+#             */
/*   Updated: 2023/04/06 15:56:22 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ER_NAME "Le nom fourni en parametre est incorecte.\n"
# define ER_NOMAP "La carte na pu etre recupere.\n"
# define ER_MAPCHAR "La carte contient des caractere imvalide.\n"
# define ER_NOSTART "La carte doit contenir une position de départ\n"
# define ER_NOEND "La carte doit contenir une sortie.\n"
# define ER_NOCOL "La carte doit contenir au moins un collectible.\n"
# define ER_MAPLEN "Chacune des lignes de la carte doivent faire la même longueur.\n"
# define ER_WALL "La carte doit être fermée par des murs sur chacun de ses côtés.\n"
# define ER_RESOLVE "La carte ne peut pas être résolu.\n"
# define WARN_NO_ENEMY "La carte ne peut pas contenir des ennemies, elle sera quand même lancé.\n"
# define WIN "Vous avez gagné bravo !\n"
# define DEATH "Vous êtes mort 💩.\n"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"
# include "../Libft/libft.h"
# include <math.h>
# include <stdio.h>

typedef struct s_assets
{
	void	*bg_2_1;
	void	*bg_2_2;
	void	*bg_2_3;
	void	*bg_1;
	void	*chest_o;
	void	*chest;
	void	*exit;
	void	*player;
	void	*enemy_0;
	void	*enemy_1;
	void	*enemy_2;
	void	*enemy_3;
	void	*wall_bl;
	void	*wall_br;
	void	*wall_tl;
	void	*wall_tr;
	void	*wall_t;
	void	*wall_b;
	void	*wall_l;
	void	*wall_r;
	void	*wall;
}				t_assets;

typedef struct s_game {
	void		*mlx;
	void		*mlx_win;
	int			game_state;
	char		*map;
	int			map_w;
	int			map_h;
	int			move;
	int			collect;
	int			player_pos;
	int			loop_state;
	t_assets	assets;
}				t_game;

// -------------------------------------------------------------- animation.c --

int		anime_enemy(t_game *game, int anim_state);
int		loop_animations(t_game *game);

// ------------------------------------------------------ check_solvability.c --

char	*spread(char *mapcpy, int pos, int *nb_to_find);
int		check_map_can_be_solved(char *map, t_game *game);

// ------------------------------------------------------------------ check.c --

int		check_enclosure(char *map);
int		check_charactere(char *map);
int		check_integrity(char *map);
int		check_map(t_game *game, char *filename);

// ------------------------------------------------------------ enemy_funct.c --

int		enemy_can_be_place(int i, char *m);
int		add_enemy(t_game *game);
char	*move_enemy(t_game *game, int from, char state, char *map_cpy);
int		change_enemys_pos(t_game *game);

// ------------------------------------------------------------------- imgs.c --

int		open_imgs(void *mlx, t_game *game);
int		close_img(t_game *g);
int		close_img_wall(t_game *g);

// ------------------------------------------------------------- maps_funct.c --

int		get_map_size(t_game *game, char *filename);
int		get_map(t_game *game, char *file);

// ------------------------------------------------------------------- move.c --

int		move_check(t_game *game, char direction);
int		update_diplayed_move(t_game *game);
int		move_player_set_datas(t_game *game, int from_pos, int x, int y);
int		update_x_y(char direction, int i, int *x, int *y);
int		move_player(t_game *game, int from_pos, char direction);

// ----------------------------------------------------------------- render.c --

int		put_image(t_game game, char c, int x, int y);
int		fill_win(t_game game);
void	*get_wall(t_game game, int x, int y);

// ---------------------------------------------------------------- so_long.c --

int		close_program(t_game *game);
int		key_press(int keycode, t_game *game);
void	check_event(t_game *game);

// ------------------------------------------------------------------ utils.c --

int		nb_occurrence(char *str, char c);
int		line_len(char *str);
int		get_ind(int pos, char *map, char directions);
int		find_index(char *map, char to_find);
int		find_x_y(t_game game, int pos, int *x, int *y);

#endif