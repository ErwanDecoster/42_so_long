/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:52:10 by edecoste          #+#    #+#             */
/*   Updated: 2023/03/08 16:22:18 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	put_image(t_game game, char c, int x, int y)
{
	void	*img;

	img = game.assets.bg_1;
	if (c == '1')
		img = get_wall(game, x, y);
	if (c == '0')
		img = game.assets.bg_1;
	if (c == 'C')
		img = game.assets.chest;
	if (c == 'O')
		img = game.assets.chest_o;
	if (c == 'P')
		img = game.assets.player;
	if (c == 'E')
		img = game.assets.exit;
	mlx_put_image_to_window(game.mlx, game.mlx_win, img, x, y);
	return (0);
}

void	*get_wall(t_game game, int x, int y)
{
	void	*img;

	img = game.assets.wall;
	if (y / 96 == 0)
		img = game.assets.wall_t;
	if (y / 96 == game.map_h - 1)
		img = game.assets.wall_b;
	if (x / 96 == 0)
		img = game.assets.wall_l;
	if (x / 96 == (game.map_w - 1))
		img = game.assets.wall_r;
	if (x / 96 == 0 && y / 96 == 0)
		img = game.assets.wall_tl;
	if (x / 96 == (game.map_w - 1) && y / 96 == 0)
		img = game.assets.wall_tr;
	if (x / 96 == 0 && y / 96 == game.map_h - 1)
		img = game.assets.wall_bl;
	if (x / 96 == (game.map_w - 1) && y / 96 == game.map_h - 1)
		img = game.assets.wall_br;
	return (img);
}

int	fill_win(t_game game)
{
	size_t	i;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < ft_strlen(game.map))
	{
		if (game.map[i] != '\n')
		{
			find_x_y(game, i, &x, &y);
			put_image(game, game.map[(game.map_w + 1) * y + x], x * 96, y * 96);
		}
	}
	return (0);
}
