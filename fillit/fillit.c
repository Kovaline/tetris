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
	close(fd);
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

char 	**changestr(char **tmp, int counter)
{
	char 	**str;
	int		i;
	int		j;
	int		k;
	int		z;

	i = 0;
	k = 0;
	z = 0;
	str = (char **)malloc((counter / 5 + 2) * sizeof(char *));
	str[k] = (char *)malloc((16 + 1) * sizeof(char));
	while (tmp[i])
	{
		j = 0;
		if (tmp[i][0] == '\0')
		{
			str[k][z] = '\0';
			k++;
			str[k] = (char *)malloc((16 + 1) * sizeof(char));
			z = 0;
		}
		while(tmp[i][j])
			str[k][z++] = tmp[i][j++];
		i++;
	}
	str[k][z] = '\0';
	str[k + 1] = 0;

	return (str);
}

int		main(int argc, char **argv)
{
	int fd;
	char **str;
	int counter;
	argc = argc + 1;
	
	str = readfile(argv[1]);
		fd = open(argv[1], O_RDONLY);
	counter = count(fd);
	close (fd);
	if (counter % 5 != 4) 
	{
		write (1, "error\n", 6);
		return (0);
	}
	if (validation(str) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	str = change(str);
	str = changestr(str, counter);
	startmap(str);
}
