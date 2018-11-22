/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:26:38 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/22 12:23:32 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

char	**newmap(int i)
{
	char	**map;
	int		col;
	int		row;

	col = 0;
	row = 0;
	map = (char **)malloc(i * sizeof(char *) + 1);
	while (row < i)
	{
		map[row] = (char *)malloc(i * sizeof(char) + 1);
		while (col < i)
		{
			map[row][col] = '.';
			col++;
		}
		map[row][col] = '\0';
		col = 0;
		row++;
	}
	map[i] = 0;
	return (map);
}

int		issafe(char *str, char **map, int row, int col)
{
	int check;
	int	i;
	int first;
	int size;

	size = ft_strlen(map[0]);
	check = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != '.' && check++ == 0)
			first = i;
		if (str[i] != '.' && ((size <= row + (i / 4) - (first / 4))
			|| (size <= col + (i % 4) - (first % 4))))
			return (0);
		else if (str[i] != '.' && map[row + (i / 4) - (first / 4)]
			[col + (i % 4) - (first % 4)] != '.')
			return (0);
		else if (str[i] != '.' && map[row + (i / 4) -
			(first / 4)][col + (i % 4) - (first % 4)] == '.')
			map[row + (i / 4) - (first / 4)]
			[col + (i % 4) - (first % 4)] = str[i];
	}
	return (1);
}

char	**rmletters(char **map, char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.')
			c = str[i];
		i++;
	}
	i = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		backtracking(char **str, char **map, int i, int size)
{
	int row;
	int col;

	row = 0;
	if (str[i] == '\0')
		return (1);
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (issafe(str[i], map, row, col) == 1 &&
				backtracking(str, map, i + 1, size) == 1)
				return (1);
			else
				map = rmletters(map, str[i]);
			col++;
		}
		row++;
	}
	return (0);
}

void	startmap(char **str)
{
	int		i;
	char	**map;
	int		j;

	j = 0;
	i = 2;
	map = newmap(i);
	while ((backtracking(str, map, 0, i)) == 0)
	{
		free(map);
		i++;
		map = newmap(i);
	}
	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
