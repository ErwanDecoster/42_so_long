/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:28:25 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/06 15:34:57 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*value;
	unsigned int	nn;
	int				len;

	nn = n;
	len = nb_len(nn);
	value = malloc(sizeof(char) * (len + 1));
	if (!value)
		return (0);
	value[len] = 0;
	if (n < 0)
		nn = -n;
	while (--len >= 0)
	{
		if (len == 0 && n < 0)
			value[0] = '-';
		else
			value[len] = nn % 10 + '0';
		nn = nn / 10;
	}
	return (value);
}
