/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:26:38 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/17 10:26:43 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

char	**newmap(int i)
{
	char **map;
	int		col;
	int		row;

	col = 0;
	row = 0;
	map = (char **)malloc(i * sizeof(char *) + 1);
	while (row < i)
	{
		map[row] = (char *)malloc(i * sizeof(char) + 1);
		while(col < i)
		{
			map[row][col] = '.';
			col++;
		}
		map[row][col] = '\0';
		col = 0;
		row++;
	}
	map[row] = 0;
	return (map);
}

int		issafe(char *str, char *map, int col)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (map[col] == '\0' && str[i] != '.')
		{
			return (0);
		}
		else if (str[i] != '.' && map[col] != '.')
			return (0);
		else if (str[i] != '.' && map[col] == '.')
		{
			map[col] = str[i];
			col++;
		}
		else if (str[i] == '.')
			i++;
	}
	return (1);
}

char	**rmletters(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '.')
				map[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	j = 0;
	return (map);
}

int	backtracking(char **str, char **map, int i)
{
	int row;
	int col;
	int check;

	row = 0;
	col = 0;
	if (str[i] == '\0')
		return (1);
	while (map[row] != '\0')
	{
		if (issafe(str[i], map[row], col) == 1)
		{
			if (backtracking(str, map, i + 1) == 1)
				return (1);
		}
		else
		{
			//puts(map[2]);

			map = rmletters(map);
			//printf("row is, %i\n", row);
			//printf("col is, %i\n", col);

			if (map[row][col + 1] == '\0')
			{
				row++;
				col = 0;
			}
			else
			{
				col++;
			}
		}
	}
	return (0);
}

void	startmap(char **str)
{
	int i;
	char **map;
	int j;

	j = 0;

	i = 2;
	map = newmap(i);
	while ((backtracking(str, map, 0)) == 0)
	{
		j = 0;
		while (map[j])
		{
		puts(map[j]);
		j++;
		}
		free(map);
		i++;
		map = newmap(i);
	}
	i = 0;
	while (map[i])
	{
		puts(map[i]);
		i++;
	}
}