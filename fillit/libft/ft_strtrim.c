/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:34:28 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/26 12:20:28 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_countstart(const char *s)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		counter++;
	}
	return (counter);
}

static int		ft_countend(const char *s, int i)
{
	int count;

	count = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		count++;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char	*copy;
	int		i;
	int		len;
	int		countstart;
	int		countend;

	if (s == NULL)
		return (NULL);
	countstart = ft_countstart(s);
	len = ft_strlen(s);
	countend = (ft_countend(s, len - 1));
	i = 0;
	if (len > countstart + countend)
	{
		copy = (char *)malloc(len - (countstart + countend) + 1);
		if (copy == NULL)
			return (NULL);
		while (s[countstart] != '\0' && countstart < (len - countend))
			copy[i++] = s[countstart++];
	}
	else
		copy = (char *)malloc(1);
	copy[i] = '\0';
	return (copy);
}
