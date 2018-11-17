/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:39:41 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/07 13:31:20 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dupe;

	len = ft_strlen(src);
	dupe = ft_strnew(len);
	if (dupe == NULL)
		return (NULL);
	return (ft_strcpy(dupe, src));
}
