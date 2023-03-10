/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:11:54 by edecoste          #+#    #+#             */
/*   Updated: 2022/11/15 13:57:16 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dup;

	if (!s || !f)
		return (0);
	i = -1;
	dup = ft_strdup(s);
	if (!dup)
		return (0);
	while (dup[++i])
		dup[i] = (*f)(i, dup[i]);
	return (dup);
}
