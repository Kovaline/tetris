/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:33:06 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/25 17:15:06 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*temp1;
	const char	*temp2;
	size_t		i;

	i = 0;
	temp1 = s1;
	temp2 = s2;
	while (i < n)
	{
		if (temp1[i] != temp2[i])
			return ((unsigned char)temp1[i] - (unsigned char)temp2[i]);
		i++;
	}
	return (0);
}
