/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:38:32 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/13 12:33:22 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(const char *s, int i, char c)
{
	int		wl;

	wl = 0;
	while (s[i + wl] != c && s[i + wl])
		wl++;
	return (wl);
}

static void	free_all(char **strs, int nb_word)
{
	int	i;

	i = 0;
	while (i < nb_word)
		free(strs[i++]);
	free(strs);
}

static char	**split_next(char **strs, char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	wl;

	i = 0;
	k = 0;
	while (k < count_word(s, c))
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		wl = word_len(s, i, c);
		while (j < wl)
			strs[k][j++] = s[i++];
		strs[k++][j] = 0;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	strs = ft_calloc(sizeof(char *), count_word(s, c) + 1);
	if (!strs)
		return (0);
	while (j < count_word(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		strs[j] = malloc(sizeof(char) * (word_len(s, i, c) + 1));
		i += word_len(s, i, c);
		if (!strs[j++])
		{
			free_all(strs, j);
			return (0);
		}
	}
	return (split_next(strs, s, c));
}
