/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:41:13 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/22 12:08:59 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		countchars2(char **str, int i, int j, int count)
{
	while (str[i][j] != '\0')
	{
		if (str[i][j] == '#')
			count++;
		j++;
	}
	return (count);
}

char	**setstr(char **str, int k, int z)
{
	str[k][z] = '\0';
	str[k + 1] = 0;
	return (str);
}
