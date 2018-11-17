/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:05:25 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/25 14:35:15 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*reverse(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmpdst;
	const char	*tmpsrc;

	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	i = n;
	while (i > 0)
	{
		tmpdst[i - 1] = tmpsrc[i - 1];
		i--;
	}
	return (tmpdst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
		reverse(dst, src, len);
	return (dst);
}
