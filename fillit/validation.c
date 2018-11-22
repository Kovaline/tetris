/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:16:28 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/22 12:00:30 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		checkvalid(char **str)
{
	int i;
	int j;
	int count;

	i = 0;
	while (str[i] != '\0')
	{
		count = 0;
		j = -1;
		while (str[i][++j] != '\0')
		{
			if (str[i][j] != '.' && str[i][j] != '#')
				return (-1);
			if (str[i][j] == '.')
				count++;
		}
		if (j > 0 && (count > 4 || j != 4))
			return (-1);
		i++;
	}
	return (1);
}

int		countchars(char **str, int i, int j, int count)
{
	if (str[i][j + 1] == '#')
		count++;
	if (str[i][j - 1] == '#')
		count++;
	if (str[i + 1] != '\0' && str[i + 1][j] == '#')
		count++;
	if (i > 0 && str[i - 1][j] == '#')
		count++;
	return (count);
}

int		checksymbols(char **str)
{
	int i;
	int count;
	int line;

	i = -1;
	count = 0;
	line = 0;
	while (str[++i] != '\0')
	{
		if (str[i][0] == '\0')
		{
			if (count != 4 || line % 4 != 0)
				return (-1);
			count = 0;
		}
		else
			line++;
		count = countchars2(str, i, 0, count);
	}
	if (count != 4 || line % 4 != 0)
		return (-1);
	return (1);
}

int		checkconnection(char **str)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		j = -1;
		if (str[i][0] == '\0')
		{
			if (count != 6 && count != 8)
				return (-1);
			count = 0;
		}
		while (str[i][++j] != '\0')
			if (str[i][j] == '#')
				count = countchars(str, i, j, count);
	}
	if (count != 6 && count != 8)
		return (-1);
	return (1);
}

int		validation(char **str)
{
	if (checkvalid(str) == -1 || checksymbols(str) == -1
		|| checkconnection(str) == -1)
		return (-1);
	return (1);
}
