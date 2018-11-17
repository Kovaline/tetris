/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:04:34 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/26 13:09:37 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int		letters(char const *s, char c)
{
	int i;
	int letters;

	i = 0;
	letters = 0;
	while (s[i] != c && s[i] != '\0')
	{
		letters++;
		i++;
	}
	return (letters);
}

static char		**fill(char **sr, char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			sr[j] = (char *)malloc((letters(s + i, c) + 1) * sizeof(char));
			while (s[i] != c && s[i] != '\0')
				sr[j][k++] = s[i++];
			sr[j++][k] = '\0';
			k = 0;
		}
	}
	sr[j] = 0;
	return (sr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**sr;

	if (s == NULL)
		return (NULL);
	sr = (char **)malloc(((words(s, c) + 1)) * sizeof(char*));
	if (sr == NULL)
		return (NULL);
	sr = fill(sr, s, c);
	return (sr);
}
