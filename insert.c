/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 01:32:53 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 12:00:08 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_insert(t_board *board, t_token *token, t_vector2 point, FILE *file)
{
	int	min;
	int	check;
	int	x;
	int	y;
	t_vector2 temp;
	temp.x = point.x;
	temp.y = point.y;

	check = 0;
	min = 0;
	y = token->indent_up - 1;
	while (++y < token->height - token->indent_down
		&& point.y < board->height)
	{
		x = token->indent_left - 1;
		point.x = temp.x;
		while (++x < token->width - token->indent_right
			&& point.x < board->width)
		{
			if (board->cells[point.y][point.x] == 1000)
				return ;
			if (token->cells[y][x] == 1
				&& board->cells[point.y][point.x] == 0)
			{
				check++;
				point.x++;
				continue ;
			}
			if (check > 1)
				return ;
			if (token->cells[y][x] == 1)
				min += board->cells[point.y][point.x];
			point.x++;
		}
		point.y++;
	}
	// fputs(ft_strjoin(ft_itoa(min), " "), file);
	// fputs(ft_strjoin(ft_itoa(token->max), "\n\n"), file);
	if (y == token->height - token->indent_down
		&& x == token->width - token->indent_right && check == 1 && min <= token->max)
	{
		token->max = min;
		token->suitable_point.x = temp.x;
		token->suitable_point.y = temp.y;
	}
}

int	output_position(t_token *token)
{
	char	*position;
	char	*temp;

	// if (!(position = ft_strjoin(position, )))
	// num = ft_strjoin(num, ft_itoa(token->suitable_point.x - token->indent_left));
	// num = ft_strjoin(num, "\n");

	if (token->max == 1000000)
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
	temp = position;
	// write(1, num, ft_strlen(num));
	return (1);
}

int	insert_token(t_board *board, t_token *token, FILE *file)
{
	t_vector2	point;

	token->max = 1000000;
	point.y = 0;
	while (point.y < board->height)
	{
		point.x = 0;
		while (point.x < board->width)
		{
			check_insert(board, token, point, file);
			point.x++;
		}
		point.y++;
	}
	// fputs(ft_strjoin(ft_itoa(token->suitable_point.y), " "), file);
	// fputs(ft_strjoin(ft_itoa(token->suitable_point.x), "\n"), file);

	if (!(output_position(token)))
		return (0);
	// fputs(num, file);
	return (1);
}
