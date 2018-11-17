/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:02:44 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/25 14:34:19 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t							i;
	unsigned char *restrict			tmpdst;
	unsigned const char *restrict	tmpsrc;
	unsigned char					v;

	tmpdst = dst;
	tmpsrc = src;
	i = 0;
	v = (unsigned char)c;
	while (i < n && tmpsrc[i] != v)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		tmpdst[i++] = v;
		return (tmpdst + i);
	}
}
