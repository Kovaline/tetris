/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:25:20 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/06 12:48:19 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *dst, char const *src)
{
	char			*new;
	size_t			len_dst;
	size_t			len_src;
	register size_t	i;

	if (!src || !dst)
		return (NULL);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (!(new = (char *)malloc((len_dst + len_src + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len_dst)
	{
		new[i] = dst[i];
		++i;
	}
	while (i < len_dst + len_src)
	{
		new[i] = src[i - len_dst];
		++i;
	}
	new[i] = '\0';
	return (new);
}
