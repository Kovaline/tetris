/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:40:39 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/25 13:24:50 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t					i;
	char *restrict			tmpdst;
	const char *restrict	tmpsrc;

	tmpdst = dst;
	tmpsrc = src;
	i = 0;
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (tmpdst);
}
