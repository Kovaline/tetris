/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:27:14 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/26 14:33:56 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	int a;

	if (str == NULL)
		return ;
	a = 0;
	while (str[a] != '\0')
	{
		ft_putchar_fd(str[a], fd);
		a++;
	}
	write(fd, "\n", 1);
}
