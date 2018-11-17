/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:31:30 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/07 14:05:43 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		addstr(int const fd, char **buff)
{
	int		bytes;
	char	*tmp2;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (tmp == NULL)
		return (-1);
	bytes = read(fd, tmp, BUFF_SIZE);
	if (bytes == -1)
		return (-1);
	tmp[bytes] = '\0';
	tmp2 = ft_strjoin(*buff, tmp);
	free(*buff);
	*buff = tmp2;
	free(tmp);
	return (bytes);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buff = NULL;
	int				bytes;
	char			*tmp;

	bytes = 1;
	if (fd < 0 || !line || BUFF_SIZE < 1 || (-1 == read(fd, buff, 0)))
		return (-1);
	if (!buff)
		buff = ft_strnew(0);
	while (bytes != 0 && ft_strchr(buff, '\n') == NULL)
		bytes = addstr(fd, &buff);
	if (bytes == -1)
		return (-1);
	if ((tmp = ft_strchr(buff, '\n')) != NULL)
	{
		tmp[0] = '\0';
		*line = ft_strdup(buff);
		ft_memmove(buff, tmp + 1, ft_strlen(tmp + 1) + 1);
		return (1);
	}
	*line = ft_strdup(buff);
	ft_strdel(&buff);
	if (ft_strlen(*line) > 0)
		return (1);
	return (0);
}
