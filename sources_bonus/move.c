/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:01 by edecoste          #+#    #+#             */
/*   Updated: 2023/05/11 14:28:17 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	move_check(t_game *game, char direction)
{
	int	temp_i;

	temp_i = get_ind(game->player_pos, game->map, direction);
	if (temp_i == -1)
		return (-1);
	if (game->map[temp_i] == '1')
		return (0);
	if (game->map[temp_i] == 'R' || game->map[temp_i] == 'r' || \
		game->map[temp_i] == 'L' || game->map[temp_i] == 'l')
		return (ft_printf(DEATH), close_program(game), 0);
	if (game->map[temp_i] == 'C')
	{
		game->collect--;
		move_player(game, game->player_pos, direction);
	}
	if (game->map[temp_i] == '0' || game->map[temp_i] == 'P' || \
		game->map[temp_i] == 'E')
		move_player(game, game->player_pos, direction);
	if (game->map[temp_i] == 'E' && game->collect == 0)
		return (ft_printf(WIN), close_program(game), 0);
	if (game->map[temp_i] == 'O')
		move_player(game, game->player_pos, direction);
	game->player_pos = temp_i;
	return (game->move++, 0);
}

int	update_diplayed_move(t_game *game)
{
	char	*temp;

	put_image(*game, '1', 96, 0);
	mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0xffffff, \
		"Nombre de mouvements :");
	temp = ft_itoa(game->move + 1);
	mlx_string_put(game->mlx, game->mlx_win, 150, 10, 0xffffff, temp);
	free(temp);
	return (0);
}

int	move_player_set_datas(t_game *game, int from_pos, int x, int y)
{
	if (game->map[from_pos] == 'C' || game->map[from_pos] == 'O')
	{
		put_image(*game, 'O', x, y);
		game->map[from_pos] = 'O';
	}
	if (game->map[from_pos] == 'E')
		put_image(*game, 'E', x, y);
	return (0);
}

int	update_x_y(char direction, int i, int *x, int *y)
{
	if (direction == 't' && i % 1000 == 0)
		*y -= 96 / 8;
	if (direction == 'b' && i % 1000 == 0)
		*y += 96 / 8;
	if (direction == 'r' && i % 1000 == 0)
		*x += 96 / 8;
	if (direction == 'l' && i % 1000 == 0)
		*x -= 96 / 8;
	return (0);
}

int	move_player(t_game *game, int fpos, char direction)
{
	int	i;
	int	x;
	int	from_x;
	int	y;
	int	from_y;

	i = -1;
	find_x_y(*game, fpos, &x, &y);
	x = x * 96;
	from_x = x;
	y = y * 96;
	from_y = y;
	move_player_set_datas(game, fpos, x, y);
	while (++i < 8000)
	{
		if ((game->map[fpos] == 'C' || game->map[fpos] == 'O') && i % 1000 == 0)
			put_image(*game, 'O', from_x, from_y);
		else if (game->map[fpos] == 'E' && i % 1000 == 0)
			put_image(*game, 'E', from_x, from_y);
		else if (i % 1000 == 0)
			put_image(*game, '0', from_x, from_y);
		update_x_y(direction, i, &x, &y);
		put_image(*game, 'P', x, y);
	}
	return (update_diplayed_move(game), 0);
}
