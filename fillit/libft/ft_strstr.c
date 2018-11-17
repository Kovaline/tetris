/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:19:32 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/30 09:48:20 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			if (to_find[j] != str[i + j])
				break ;
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (0);
}
