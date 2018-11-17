/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:25:47 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/30 09:48:41 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	k;

	i = 0;
	j = -1;
	size = ft_strlen(to_find);
	k = len;
	if (len == 0)
		return (NULL);
	if (str == to_find || to_find == NULL)
		return ((char *)str);
	while (str[i] != '\0' && (len-- - size + 1 > 0))
	{
		j = -1;
		while (to_find[++j] != '\0' && j < k - 1)
			if (to_find[j] != str[i + j])
				break ;
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
