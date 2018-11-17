/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:50:33 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/08 13:36:56 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

static int	count(int fd)
{
	int counter;
	char	*line1;

	counter = 0;
	while (get_next_line(fd, &line1) > 0)
		counter++;
	return (counter);

}

char	**readfile(char *str)
{
	char *line;
	char **tmp;
	int		i;
	int		counter;
	int		fd;

	i = 0;
	fd = open(str, O_RDONLY);
	counter = count(fd);
	close(fd);
	tmp = (char **)malloc(counter * sizeof(char *) + 1);
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp[i] = strdup(line);
		i++;
	}
	i = 0;
	return (tmp);
}

char	**change(char **str)
{
	int i;
	int j;
	char a;

	a = 'A';
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i][0] == '\0')
			a++;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
				str[i][j] = a;
			j++;
		}
		i++;
		j = 0;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int fd;
	char **str;
	int counter;
	

	str = readfile(argv[1]);
	//str = cuttet(str);
	if (validation(str) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	
	str = change(str);
	int i = 0;
	while (str[i] != '\0')
	{

		puts(str[i]);

		i++;
	}
	startmap(str);
}
