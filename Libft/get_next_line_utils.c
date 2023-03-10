/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:29:21 by edecoste          #+#    #+#             */
/*   Updated: 2023/02/21 18:08:02 by edecoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft2_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft2_strdup(s2));
	if (!s2)
		return (ft2_strdup(s1));
	len1 = ft2_strlen(s1);
	len2 = ft2_strlen(s2);
	join = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == NULL)
		return (NULL);
	join[0] = 0;
	ft2_strlcat(join, s1, len1 + 1);
	ft2_strlcat(join, s2, len1 + len2 + 1);
	return (join);
}

char	*ft2_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (0);
	if (ft2_strlen(s) <= start)
		len = 0;
	else if (ft2_strlen(s) < start + len)
		len = ft2_strlen(s) - start;
	sub = (char *) malloc(sizeof(char) * len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	*ft2_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*copy;

	i = 0;
	len = ft2_strlen(str);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == 0)
		return (0);
	while (str[i] && i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

size_t	ft2_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	if ((!src || !dst) && size == 0)
		return (0);
	dst_len = ft2_strlen(dst);
	src_len = ft2_strlen(src);
	if (dst_len < size - 1 && size > 0)
	{
		while (src[i] && dst_len + i < size - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = 0;
	}
	if (dst_len > size)
		dst_len = size;
	return (dst_len + src_len);
}

size_t	ft2_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
