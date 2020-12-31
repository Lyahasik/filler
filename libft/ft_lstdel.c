/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:52:48 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/22 21:35:32 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*delist;

	if (alst && del)
	{
		while (*alst)
		{
			delist = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = delist;
		}
	}
}
