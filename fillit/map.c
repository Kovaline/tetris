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


int		ft_dots(char *str)
{
	int i;

	i = 0;
	while (str[i] == '.')
		i++;
	return (i);
}
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
	map[i] = 0;
	return (map);
}

int		issafe(char *str, char **map,int row, int col, int size)
{
	int first;
	int	i;

	first = ft_dots(str);
	i = first;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && ((size - 1 < row + (i / 4) - (first / 4)) || (size - 1 < col + (i % 4) - (first % 4))))
		{
			//printf("return end\n");
			return (0);
		}
		else if (str[i] != '.' && map[row + (i / 4) - (first / 4)][col + (i % 4) - (first % 4)] != '.')
		{
			//printf("return 0\n");
			return (0);
		}
		else if (str[i] != '.' && map[row + (i / 4) - (first / 4)][col + (i % 4) - (first % 4)] == '.')
		{
			//map[row + (i / 4) - (first / 4)][col + (i % 4) - (first % 4)] = str[i];
			i++;
		}
		else if (str[i] == '.')
			i++;
	}
	//printf("return 1\n");
	return (1);
}

char	**fillmap(char *str, char **map, int row, int col)
{
	int i;
	int first;

	first = ft_dots(str);
	i = first;
	while (str[i] != '\0')
	{
		if (str[i] != '.')
			map[row + (i / 4) - (first / 4)][col + (i % 4) - (first % 4)] = str[i];
		i++;
	}
	return (map);
}

char	**rmletters(char **map, char *str)
{
	int i;
	int j;
	char c;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.')
			c = str[i];
		i++;
	}
	i = 0;
	while (map[i] != '\0')
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	j = 0;
	return (map);
}

int	backtracking(char **str, char **map, int i, int size)
{
	int row;
	int col;
	int check;

int j = 0;
	row = 0;
	col = 0;
	if (str[i] == '\0')
		return (1);
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (issafe(str[i], map, row, col, size) == 1)
			{
				map = fillmap(str[i], map, row, col);
				if (backtracking(str, map, i + 1, size) == 1)
					return (1);
			}
			else
			{
			j = 0;
			//puts(map[2]);
		/*	while (map[j])
	{
	puts(map[j]);
		j++;
	}*/
			map = rmletters(map, str[i]);
			//printf("row is, %i\n", row);
			//printf("col is, %i\n", col);

			/*if (map[row][col + 1] == '\0')
			{
				row++;
				col = 0;
			}
			else
			{
				col++;
			}*/
			//printf("%i %i\n", row, col);
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	free_square(char **map, int size)
{
	int j;

	j = 0;
	while (j < size)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

void	startmap(char **str)
{
	int i;
	char **map;
	int j;

	j = 0;

	i = 2;
	map = newmap(i);
	while ((backtracking(str, map, 0, i)) == 0)
	{
		free_square(map, i);
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