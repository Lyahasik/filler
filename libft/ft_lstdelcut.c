/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:02:15 by dhorker           #+#    #+#             */
/*   Updated: 2019/02/07 15:14:27 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelcut(t_list **start, t_list **alst)
{
	t_list	*anc;

	if (alst && (*start)->next)
	{
		anc = *start;
		if (*start != *alst)
			while (anc->next != *alst)
				anc = anc->next;
		if (anc->next == *alst)
			anc->next = (*alst)->next;
		else if (anc->next != NULL)
			*start = (*start)->next;
		free((*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}
