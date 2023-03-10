/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:08:09 by edecoste          #+#    #+#             */
/*   Updated: 2022/11/17 11:29:41 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	slen;
	int	start;
	int	end;

	slen = ft_strlen(s1);
	start = -1;
	end = slen;
	while (++start < slen && s1[start])
		if (ft_strchr(set, s1[start]) == 0)
			break ;
	while (--end < slen && s1[end] && end != 0)
		if (ft_strchr(set, s1[end]) == 0)
			break ;
	return (ft_substr(s1, start, (end - start + 1)));
}
