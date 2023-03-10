/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:36:58 by edecoste          #+#    #+#             */
/*   Updated: 2023/02/02 15:33:39 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*var;

	if (size && count > 2147483647 / size)
		return (0);
	var = malloc(count * size);
	if (!var)
		return (0);
	ft_bzero(var, count * size);
	return (var);
}
