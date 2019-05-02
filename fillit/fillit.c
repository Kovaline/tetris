/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:50:33 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/24 13:00:35 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		count(int fd)
{
	int		counter;
	char	*line1;

	counter = 0;
	while (get_next_line(fd, &line1) > 0)
	{
		free(line1);
		counter++;
	}
	close(fd);
	free(line1);
	return (counter);
}

char	**readfile(char *str, int counter)
{
	char	*line;
	char	**tmp;
	int		i;
	int		fd;

	i = 0;
	if ((tmp = (char **)malloc((counter + 1) * sizeof(char *))) == NULL)
		return (NULL);
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp[i] = line;
		i++;
	}
	tmp[i] = 0;
	free(line);
	close(fd);
	return (tmp);
}

char	**change(char **str)
{
	int		i;
	int		j;
	char	a;

	a = 'A';
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i][0] == '\0')
			a++;
		while (str[i][j] != '\0')
		{
			if (a > 90)
				return (NULL);
			if (str[i][j] == '#')
				str[i][j] = a;
			j++;
		}
		i++;
		j = 0;
	}
	return (str);
}

char	**changestr(char **tmp, int counter)
{
	char			**str;
	struct s_norme	t;

	t.i = -1;
	t.k = 0;
	t.z = 0;
	if ((str = (char **)malloc((counter / 5 + 2) * sizeof(char *))) == NULL)
		return (NULL);
	if ((str[t.k] = (char *)malloc((16 + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (tmp[++t.i])
	{
		t.j = 0;
		if (tmp[t.i][0] == '\0')
		{
			str[t.k++][t.z] = '\0';
			if ((str[t.k] = (char *)malloc((16 + 1) * sizeof(char))) == NULL)
				return (NULL);
			t.z = 0;
		}
		while (tmp[t.i][t.j])
			str[t.k][t.z++] = tmp[t.i][t.j++];
	}
	str = setstr(str, tmp, t.k, t.z);
	return (str);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**str;
	int		counter;

	if (argc != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	counter = count(fd);
	if ((str = readfile(argv[1], counter)) == NULL)
		error();
	if (counter % 5 != 4 || validation(str) == -1
		|| (str = change(str)) == NULL)
		error();
	if ((str = changestr(str, counter)) == NULL)
		error();
	startmap(str);
	return (0);
}
