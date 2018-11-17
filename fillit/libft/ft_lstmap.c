/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:49:33 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/30 13:07:16 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*next;

	if (lst == NULL || !f)
		return (NULL);
	list = (t_list *)malloc(sizeof(lst));
	if (list == NULL)
		return (NULL);
	list = f(lst);
	next = list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		next->next = f(lst);
		next = next->next;
	}
	return (list);
}
