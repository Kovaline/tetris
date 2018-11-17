/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:16:28 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/13 13:16:30 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		checkfigure(char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i][j])
		{
			if (str[i][j] == '#')
				if (i > 0 && str[i + 1] != '\0' && str[i][j + 1] != '#' && str[i][j - 1] != '#' 
					&& str[i + 1][j] != '#' && str[i - 1][j] != '#')
					return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int		checkvalid(char **str)
{
	int i;
	int j;
	int count;
	int count2;

	i = 0;
	j = 0;

	while (str[i] != '\0')
	{
		count = 0;
		count2 = 0;
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] != '.' && str[i][j] != '#')
				return (-1);
			if (str[i][j] == '.')
				count++;
			count2++;
			j++;
		}
		if (j > 0 && (count > 4 || count2 != 4))
			return (-1);
		i++;
	}
	return (1);
}

int		checksymbols(char **str)
{
	int i;
	int j;
	int count;
	int line;
	
	i = 0;
	count = 0;
	line = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i][0] == '\0')
		{
			if (count != 4 || line % 4 != 0)
				return (-1);
			count = 0;
			i++;
			continue ;
		}		
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
				count++;
			j++;
		}
		line++;
		i++;
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

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i][0] == '\0')
		{
			if (count != 6 && count != 8)
				return (-1);
			count = 0;
		}				
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
			{
				if (str[i][j + 1] == '#')
					count++;
				if (str[i][j - 1] == '#')
					count++;
				if (str[i + 1] != '\0' && str[i + 1][j] == '#')
					count++;
				if (i > 0 && str[i - 1][j] == '#')
					count++;
			}
			j++;
		}
		i++;
	}
		if (count != 6 && count != 8)
			return (-1);
	return (1);
}

int		validation(char **str)
{
	if (checkvalid(str) == -1 || checksymbols(str) == -1 
		|| checkfigure(str) == -1 || checkconnection(str) == -1)
		return (-1);
	return (1);
}