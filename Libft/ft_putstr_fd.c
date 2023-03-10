/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:13:41 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/06 15:30:01 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		rt_val;

	i = 0;
	rt_val = 0;
	if (!s)
		i = ft_putstr_fd("(null)", fd);
	else
	{
		while (s[i])
		{
			rt_val = ft_putchar_fd(s[i++], fd);
			if (rt_val == -1)
				return (rt_val);
		}
	}
	return (i);
}
