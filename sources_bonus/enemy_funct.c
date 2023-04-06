/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:24:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/04/06 14:30:45 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	enemy_can_be_place(int i, char *m)
{
	if (m[get_ind(i, m, 'l')] == '0' && m[get_ind(i, m, 'b')] == '0')
		if (m[i] == '0' && m[get_ind(get_ind(i, m, 'l'), m, 'b')] == '0')
			if (m[get_ind(i, m, 't')] != 'R' && \
				m[get_ind(get_ind(i, m, 'l'), m, 't')] != 'R')
				return (1);
	return (0);
}

int	add_enemy(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		if ((rand() % 5) < 1 && enemy_can_be_place(i, game->map))
			game->map[i] = 'R';
	return (0);
}

int	kill_player(t_game *game, int enemy_pos)
{
	if (enemy_pos == game->player_pos)
		return (ft_printf(DEATH), close_program(game), 0);
	return (0);
}

char	*move_enemy(t_game *game, int from, char state, char *map_cpy)
{
	int	x;
	int	y;

	find_x_y(*game, from, &x, &y);
	put_image(*game, '0', x * 96, y * 96);
	map_cpy[from] = '0';
	if (state == 'R')
		return (put_image(*game, 'R', x * 96, y * 96 + 96), \
				kill_player(game, get_ind(from, game->map, 'b')), \
				map_cpy[get_ind(from, game->map, 'b')] = 'r', map_cpy);
	else if (state == 'r')
		return (put_image(*game, 'R', x * 96 - 96, y * 96), \
				kill_player(game, get_ind(from, game->map, 'l')), \
				map_cpy[get_ind(from, game->map, 'l')] = 'l', map_cpy);
	else if (state == 'l')
		return (put_image(*game, 'R', x * 96, y * 96 - 96), \
				kill_player(game, get_ind(from, game->map, 't')), \
				map_cpy[get_ind(from, game->map, 't')] = 'L', map_cpy);
	else if (state == 'L')
		return (put_image(*game, 'R', x * 96 + 96, y * 96), \
				kill_player(game, get_ind(from, game->map, 'r')), \
				map_cpy[get_ind(from, game->map, 'r')] = 'R', map_cpy);
	return (map_cpy);
}

int	change_enemys_pos(t_game *game)
{
	char	*map_cpy;
	int		i;

	i = -1;
	map_cpy = ft_strdup(game->map);
	while (game->map[++i])
		if (game->map[i] == 'R' || game->map[i] == 'r' || \
			game->map[i] == 'L' || game->map[i] == 'l')
			if ((rand() % 5) < 3)
				map_cpy = move_enemy(game, i, game->map[i], map_cpy);
	free(game->map);
	game->map = map_cpy;
	return (0);
}
