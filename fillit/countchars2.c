/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:41:13 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/24 15:46:02 by ikovalen         ###   ########.fr       */
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

char	**setstr(char **str, char **tmp, int k, int z)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
		free(tmp[i++]);
	free(tmp);
	str[k][z] = '\0';
	str[k + 1] = 0;
	return (str);
}

void	free_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}
