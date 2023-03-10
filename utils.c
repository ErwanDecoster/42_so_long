/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:22 by edecoste          #+#    #+#             */
/*   Updated: 2023/03/08 15:04:44 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// conte le nombre d'ocurence d'un caractere.
int	nb_occurrence(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == c)
			count++;
	return (count);
}

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		if (str[i - 1] == '\n')
			return (i - 1);
	return (i);
}

int	get_index(int pos, char *map, char directions)
{
	int	line_l;

	line_l = line_len(map) + 1;
	if (map[pos] == '\n')
		return (-1);
	if (directions == 't')
		if (pos > line_l)
			return (pos - line_l);
	if (directions == 'b')
		if (pos < line_l * nb_occurrence(map, '\n'))
			return (pos + line_l);
	if (directions == 'l')
		if (map[pos - 1] && map[pos - 1] != '\n')
			return (pos - 1);
	if (directions == 'r')
		if (map[pos + 1] && map[pos + 1] != '\n')
			return (pos + 1);
	return (-1);
}

int	find_index(char *map, char to_find)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != to_find)
		i++;
	if (map[i] == to_find)
		return (i);
	return (-1);
}

int	find_x_y(t_game game, int pos, int *x, int *y)
{
	int	i;

	i = 0;
	*x = 0;
	*y = 0;
	while (game.map[i] && i < pos)
	{
		if (game.map[i] == '\n')
		{
			*y = *y + 1;
			*x = 0;
		}
		else
			*x = *x + 1;
		i++;
	}
	return (0);
}
