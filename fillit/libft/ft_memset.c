/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:04:39 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/25 13:17:55 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = b;
	if (len != 0)
	{
		while (i < len)
		{
			tmp[i] = c;
			i++;
		}
	}
	return (tmp);
}
