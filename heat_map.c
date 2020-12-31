/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:25:44 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/30 19:24:44 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	search_enemy(t_board *board, t_vector2 *enemy)
// {
// 	enemy->y = 0;
// 	while (enemy->y < board->height)
// 	{
// 		enemy->x = 0;
// 		while (enemy->x < board->width)
// 		{
// 			if (board->cells[enemy->y][enemy->x] == 1000)
// 				return ;
// 			enemy->x++;
// 		}
// 		enemy->y++;
// 	}
// }

// void	temperature_drop(t_board *board, t_vector2 enemy)
// {
// 	//output_board(*board);
// 	//printf("%d\n", board->cells[enemy.y][enemy.x]);
// 	if (board->cells[enemy.y][enemy.x] != 1000)
// 	{
// 		board->cells[enemy.y][enemy.x] = search_max(board, enemy) - 1;
// 	}
// 	step(board, enemy, 1, 0);
// 	step(board, enemy, -1, 0);
// 	step(board, enemy, 0, 1);
// 	step(board, enemy, 0, -1);
// 	return ;
// }

void	first_step_temperature(t_board *board)
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

int	steps_temperature(t_board *board, int size)
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

void	heat_map(t_board *board, FILE *file)
{
	int	size;

	first_step_temperature(board);
	// output_board(board, file);
	size = 1;
	while ((size = steps_temperature(board, size)) != 0)
	{
		// fputs("\n", file);
		// output_board(board, file);
		size++;
	}
	// output_board(board, file);
}
