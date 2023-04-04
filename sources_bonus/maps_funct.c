/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:24:53 by edecoste          #+#    #+#             */
/*   Updated: 2023/04/03 17:48:43 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	get_map_size(t_game *game, char *filename)
{
	int		fd;
	char	c;
	int		i;
	int		rt_val;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf_e(ER_NOMAP), close_program(game), 0);
	rt_val = 1;
	while (rt_val)
	{
		rt_val = read(fd, &c, 1);
		if (rt_val == -1)
			return (close_program(game), 0);
		if (rt_val == 1)
			i++;
	}
	close(fd);
	return (i);
}

int	get_map(t_game *game, char *file)
{
	char	c;
	int		rt_val;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf_e(ER_NOMAP), close_program(game), 0);
	i = 0;
	rt_val = 1;
	while (rt_val > 0)
	{
		rt_val = read(fd, &c, 1);
		if (rt_val == -1)
			return (close_program(game), 0);
		if (rt_val != 0)
			game->map[i] = c;
		i++;
	}
	close(fd);
	return (0);
}

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

int	move_enemy(t_game *game, int from, char state)
{
	int	x;
	int	y;
	
	find_x_y(*game, from, &x, &y);
	put_image(*game, '0', x * 96, y * 96);
	game->map[from] = '0';
	if (state == 'R')
	{
		put_image(*game, 'R', x * 96, y * 96 + 96);
		game->map[get_ind(from, game->map, 'b')] = 'r';
		return (0);
	}
	if (state == 'r')
	{
		put_image(*game, 'R', x * 96 - 96, y * 96);
		game->map[get_ind(from, game->map, 'l')] = 'l';
		return (0);
	}
	if (state == 'l')
	{
		put_image(*game, 'R', x * 96, y * 96 - 96);
		game->map[get_ind(from, game->map, 't')] = 'L';
		return (0);
	}
	if (state == 'L')
	{
		put_image(*game, 'R', x * 96 + 96, y * 96);
		game->map[get_ind(from, game->map, 'r')] = 'R';
		return (0);
	}
	return (0);
}

int	change_enemys_pos(t_game *game, size_t pos)
{
	if (game->map[pos] == 'R' || game->map[pos] == 'r' || game->map[pos] == 'L' || game->map[pos] == 'l')
	{
		if ((rand() % 5) < 3 )
		{
			move_enemy(game, pos, game->map[pos]);
			ft_printf("nb move :%d\n\n", game->move);
			ft_printf("%s\n\n", game->map);
		}
	}
	if (pos < ft_strlen(game->map))
	change_enemys_pos(game, pos + 1);
	return (0);
}
