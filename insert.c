/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 01:32:53 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 16:37:06 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_vector2	create_vector2(int x, int y)
{
	t_vector2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

static void			check_path(t_token *token, t_vector2 i, int min)
{
	if (i.y == token->height - token->indent_down
		&& i.x == token->width - token->indent_right
		&& token->check == 1 && min <= token->min)
	{
		token->min = min;
		token->suitable_point.x = token->begin.x;
		token->suitable_point.y = token->begin.y;
	}
}

static void			check_insert(t_board *board, t_token *t, t_vector2 point,
									int min)
{
	t_vector2	i;

	i.y = t->indent_up - 1;
	while (++i.y < t->height - t->indent_down && point.y < board->height)
	{
		i.x = t->indent_left - 1;
		point.x = t->begin.x;
		while (++i.x < t->width - t->indent_right && point.x < board->width)
		{
			if (t->cells[i.y][i.x] == 1 && board->cells[point.y][point.x] == 0)
			{
				t->check++;
				point.x++;
				continue ;
			}
			if (t->check > 1 || board->cells[point.y][point.x] == 1000)
				return ;
			if (t->cells[i.y][i.x] == 1)
				min += board->cells[point.y][point.x];
			point.x++;
		}
		point.y++;
	}
	check_path(t, i, min);
}

static int			output_position(t_token *token)
{
	char	*position;

	if (token->min == 1000000)
	{
		write(1, "0 0\n", 5);
		return (0);
	}
	if (!(position = ft_itoa(token->suitable_point.y - token->indent_up)))
		return (0);
	write(1, position, ft_strlen(position));
	free(position);
	write(1, " ", 1);
	if (!(position = ft_itoa(token->suitable_point.x - token->indent_left)))
		return (0);
	write(1, position, ft_strlen(position));
	free(position);
	write(1, "\n", 1);
	return (1);
}

int					insert_token(t_board *board, t_token *token)
{
	t_vector2	point;
	int			min;

	token->min = 1000000;
	min = 0;
	point.y = 0;
	while (point.y < board->height)
	{
		point.x = 0;
		while (point.x < board->width)
		{
			token->check = 0;
			token->begin = create_vector2(point.x, point.y);
			check_insert(board, token, point, min);
			point.x++;
		}
		point.y++;
	}
	if (!(output_position(token)))
		return (0);
	return (1);
}
