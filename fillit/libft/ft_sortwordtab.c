/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:33:00 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/29 13:35:27 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sortwordtab(char **tab)
{
	int		i;
	int		j;
	char	*c;
	int		k;

	k = 0;
	j = 0;
	i = 0;
	while (tab[k] != (char*)NULL)
		k++;
	while (i++ < k)
	{
		while (j < (k - 1))
		{
			if ((ft_strcmp(tab[j], tab[j + 1])) > 0)
			{
				c = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = c;
			}
			j++;
		}
		j = 0;
	}
	return (tab);
}
