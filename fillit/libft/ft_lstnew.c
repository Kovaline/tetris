/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:17:07 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/29 12:00:00 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	tmp->content = malloc(content_size);
	if (tmp->content == NULL)
		return (NULL);
	ft_memcpy(tmp->content, content, content_size);
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
