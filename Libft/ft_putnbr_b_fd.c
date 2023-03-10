/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:55:26 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/06 15:36:41 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_b_fd(unsigned long int nbr, char *base, int fd)
{
	size_t		base_len;
	int			rt_value;
	int			temp;

	base_len = ft_strlen(base);
	rt_value = 0;
	temp = 0;
	if (nbr >= base_len)
	{
		ft_putnbr_b_fd(nbr / base_len, base, fd);
		ft_putnbr_b_fd(nbr % base_len, base, fd);
	}
	else
	{
		temp = ft_putchar_fd(base[nbr], fd);
		if (temp == -1)
			return (temp);
	}
	while (nbr >= base_len)
	{
		nbr /= base_len;
		rt_value++;
	}
	return (++rt_value);
}
