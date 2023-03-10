/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:09:33 by edecoste          #+#    #+#             */
/*   Updated: 2023/01/20 16:49:53 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	redirect(const char c, va_list vl, int fd)
{
	int	rt;

	rt = 0;
	if (c == 'c')
		rt = ft_putchar_fd(va_arg(vl, int), fd);
	else if (c == 's')
		rt = ft_putstr_fd(va_arg(vl, char *), fd);
	else if (c == 'p')
	{
		rt = ft_putstr_fd("0x", fd);
		if (rt == -1)
			return (rt);
		rt += ft_putnbr_b_fd(va_arg(vl, unsigned long), "0123456789abcdef", fd);
	}
	else if (c == 'd' || c == 'i')
		rt = ft_putnbr_fd(va_arg(vl, long int), fd);
	else if (c == 'u')
		rt = ft_putnbr_b_fd(va_arg(vl, unsigned int), "0123456789", fd);
	else if (c == 'x')
		rt = ft_putnbr_b_fd(va_arg(vl, unsigned int), "0123456789abcdef", fd);
	else if (c == 'X')
		rt = ft_putnbr_b_fd(va_arg(vl, unsigned int), "0123456789ABCDEF", fd);
	else if (c == '%')
		rt = ft_putchar_fd('%', fd);
	return (rt);
}

int	ft_printf(const char *s, ...)
{
	va_list	vl;
	int		rt_val;
	int		i;
	int		tmp;

	va_start(vl, s);
	i = -1;
	tmp = 0;
	rt_val = 0;
	if (write(1, 0, 0) != 0)
		return (-1);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			tmp = redirect(s[++i], vl, 1);
			if (tmp == -1)
				return (-1);
			rt_val += tmp;
		}
		else if (s[i] != '%')
			rt_val += ft_putchar_fd(s[i], 1);
	}
	va_end(vl);
	return (rt_val);
}
