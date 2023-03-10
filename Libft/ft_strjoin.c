/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:22:46 by edecoste          #+#    #+#             */
/*   Updated: 2023/02/21 19:12:53 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	char	*value;

	i = 0;
	value = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!value)
		return (0);
	while (s1[i])
	{
		value[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		value[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	value[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (value);
}
