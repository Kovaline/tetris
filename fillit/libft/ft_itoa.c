/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:45:34 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/26 14:33:39 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		checknum(int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*positive(char *sr, int numbers, int n)
{
	while (n != 0)
	{
		sr[numbers - 1] = (n % 10 + 48);
		numbers--;
		n = n / 10;
	}
	return (sr);
}

static char		*negative(char *sr, int numbers, int n)
{
	while (n != 0)
	{
		sr[numbers - 1] = ('0' - n % 10);
		numbers--;
		n = n / 10;
	}
	sr[numbers - 1] = '-';
	return (sr);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*sr;
	int		numbers;

	if (n == 0 || n == -0)
	{
		sr = (char *)malloc(2);
		sr[0] = '0';
		sr[1] = '\0';
		return (sr);
	}
	numbers = checknum(n);
	sr = (char *)malloc(numbers + 1);
	if (sr == NULL)
		return (NULL);
	i = numbers;
	if (n > 0)
		sr = positive(sr, numbers, n);
	else
		sr = negative(sr, numbers, n);
	sr[i] = '\0';
	return (sr);
}
