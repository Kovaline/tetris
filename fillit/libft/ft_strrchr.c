/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:28:27 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/29 14:40:02 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int z;
	int len;

	i = 0;
	z = -1;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			z = i;
		i++;
	}
	if (z == -1)
		return (NULL);
	else
		return ((char *)s + z);
}
