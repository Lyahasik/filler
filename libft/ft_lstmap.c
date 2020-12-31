/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:08:30 by dhorker           #+#    #+#             */
/*   Updated: 2019/04/14 18:06:46 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*list;

	if (!(res = f(lst)))
		return (0);
	list = res;
	while ((lst = lst->next))
	{
		if (!(list->next = f(lst)))
		{
			while ((list = res))
			{
				res = res->next;
				free(list->content);
				free(list);
			}
			return (0);
		}
		list = list->next;
	}
	return (res);
}
