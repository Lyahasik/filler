/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:25:44 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 16:38:33 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	first_step_temperature(t_board *board)
{
	int	x;
	int	y;

	y = -1;
	while (++y < board->height)
	{
		x = -1;
		while (++x < board->width)
		{
			if (board->cells[y][x] != -1)
				continue ;
			if ((x < board->width - 1 && board->cells[y][x + 1] == 1000)
				|| (x > 0 && board->cells[y][x - 1] == 1000)
				|| (y < board->height - 1 && board->cells[y + 1][x] == 1000)
				|| (y > 0 && board->cells[y - 1][x] == 1000))
				board->cells[y][x] = 1;
		}
	}
}

static int	steps_temperature(t_board *board, int size)
{
	int	x;
	int	y;
	int	empty;

	empty = 0;
	y = -1;
	while (++y < board->height)
	{
		x = -1;
		while (++x < board->width)
		{
			if (board->cells[y][x] != -1)
				continue ;
			if ((x < board->width - 1 && board->cells[y][x + 1] == size)
				|| (x > 0 && board->cells[y][x - 1] == size)
				|| (y < board->height - 1 && board->cells[y + 1][x] == size)
				|| (y > 0 && board->cells[y - 1][x] == size))
			{
				board->cells[y][x] = size + 1;
				empty = 1;
			}
		}
	}
	return ((empty == 1) ? size : 0);
}

void		heat_map(t_board *board)
{
	int	size;

	first_step_temperature(board);
	size = 1;
	while ((size = steps_temperature(board, size)) != 0)
	{
		size++;
	}
}
