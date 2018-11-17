/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:07:06 by ikovalen          #+#    #+#             */
/*   Updated: 2018/07/13 22:33:53 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strintsort(int *tab, int size)
{
	int		a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i != size)
	{
		while (j != size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				a = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = a;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
