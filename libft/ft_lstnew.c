/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 10:37:40 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/22 21:45:30 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(void *lst, size_t n)
{
	free(lst);
	n++;
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*create;

	if (!(create = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!(create->content = malloc(content_size)))
	{
		ft_lstdelone(&create, ft_free);
		return (0);
	}
	create->content = (content)
	? ft_memcpy(create->content, content, content_size) : NULL;
	create->content_size = (content) ? content_size : 0;
	create->next = NULL;
	return (create);
}
