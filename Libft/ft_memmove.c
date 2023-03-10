/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:43:27 by edecoste          #+#    #+#             */
/*   Updated: 2022/11/15 14:05:44 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dest > src)
	{
		i = n;
		while (--i < n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	if (src > dest)
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
