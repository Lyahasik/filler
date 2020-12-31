/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:47:44 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 11:52:15 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	free_token(t_token *token)
{
	int	i;

	if (token->cells)
	{
		i = -1;
		while (++i < token->height)
		{
			free(token->cells[i]);
			token->cells[i] = NULL;
		}
		free(token->cells);
		token->cells = NULL;
	}
	return (0);
}

int	free_board(t_board *board)
{
	int	i;

	if (board->cells)
	{
		i = -1;
		while (++i < board->height)
		{
			free(board->cells[i]);
			board->cells[i] = NULL;
		}
		free(board->cells);
		board->cells = NULL;
	}
	return (0);
}
