/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:39:55 by edecoste          #+#    #+#             */
/*   Updated: 2023/03/10 16:27:11 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

//La carte doit être fermée par des murs sur chacun de ses côtés.
int	check_enclosure(char *map)
{
	int	i;
	int	j;
	int	line_l;

	i = -1;
	line_l = line_len(map);
	while (++i <= nb_occurrence(map, '\n'))
	{
		j = i * (line_l + 1);
		if (i == 0 || i == nb_occurrence(map, '\n'))
		{
			while (j < i * (line_l + 1) + line_l)
				if (map[j++] != '1')
					return (EXIT_FAILURE);
		}
		else
			if (map[j] != '1' || map[j + line_l - 1] != '1')
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//Chacune des lignes de la carte doivent faire la même longueur.
int	check_integrity(char *map)
{	
	int	i;
	int	j;
	int	line_l;

	line_l = line_len(map);
	j = 0;
	while (j <= nb_occurrence(map, '\n'))
	{
		i = 0;
		while (map[i + j * (line_l + 1)] && map[i + j * (line_l + 1)] != '\n')
			i++;
		if (i != line_l)
			return (EXIT_FAILURE);
		j++;
	}
	return (EXIT_SUCCESS);
}

int	check_charactere(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
		if (map[i] != '1' && map[i] != '0' && map[i] != 'C' && map[i] != 'P' \
			&& map[i] != 'E' && map[i] != '\n')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i--;
	if (i < 4)
		return (EXIT_FAILURE);
	if (filename[i] != 'r' || filename[i - 1] != 'e' || filename[i - 2] != 'b' \
		|| filename[i - 3] != '.')
		return (EXIT_FAILURE);
	if (filename[i - 4] == '/')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// verifie la validiter de la map.
int	check_map(t_game *game, char *filename)
{
	if (check_filename(filename))
		return (ft_printf_e(ER_NAME), close_program(game));
	game->map = ft_calloc(get_map_size(game, filename) + 1, sizeof(char));
	if (!game->map)
		return (close_program(game), 0);
	game->game_state = 1;
	get_map(game, filename);
	game->map_h = nb_occurrence(game->map, '\n') + 1;
	game->map_w = line_len(game->map);
	if (check_charactere(game->map))
		return (ft_printf_e(ER_MAPCHAR), close_program(game));
	if (nb_occurrence(game->map, 'P') != 1)
		return (ft_printf_e(ER_NOSTART), close_program(game));
	if (nb_occurrence(game->map, 'E') != 1)
		return (ft_printf_e(ER_NOEND), close_program(game));
	if (nb_occurrence(game->map, 'C') < 1)
		return (ft_printf_e(ER_NOCOL), close_program(game));
	if (check_integrity(game->map))
		return (ft_printf_e(ER_MAPLEN), close_program(game));
	if (check_enclosure(game->map))
		return (ft_printf_e(ER_WALL), close_program(game));
	game->game_state = 2;
	if (check_map_can_be_solved(game->map, game))
		return (ft_printf_e(ER_RESOLVE), close_program(game));
	return (0);
}
