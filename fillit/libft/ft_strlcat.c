/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:04:54 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/26 15:04:40 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	z;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(dst);
	z = ft_strlen(src);
	if (size == 0)
		return (z);
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i < size - 1)
		dst[i++] = src[j++];
	if (size > k)
	{
		dst[i] = '\0';
		return (z + i - j);
	}
	return (z + i);
}
