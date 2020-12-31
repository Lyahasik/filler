/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indents.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:38:22 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/30 12:45:15 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	count_indent_left(t_token *token)
{
	int	x;
	int	y;

	x = 0;
	while (x < token->width)
	{
		y = 0;
		while (y < token->height)
		{
			if (token->cells[y][x] == 1)
			{
				token->indent_left = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

static void	count_indent_right(t_token *token)
{
	int	x;
	int	y;

	x = token->width - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < token->height)
		{
			if (token->cells[y][x] == 1)
			{
				token->indent_right = token->width - x - 1;
				return ;
			}
			y++;
		}
		x--;
	}
}

static void	count_indent_up(t_token *token)
{
	int	x;
	int	y;

	y = 0;
	while (y < token->height)
	{
		x = token->indent_left;
		while (x < token->width)
		{
			if (token->cells[y][x] == 1)
			{
				token->indent_up = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	count_indent_down(t_token *token)
{
	int	x;
	int	y;

	y = token->height - 1;
	while (y >= 0)
	{
		x = token->indent_left;
		while (x < token->width)
		{
			if (token->cells[y][x] == 1)
			{
				token->indent_down = token->height - y - 1;
				return ;
			}
			x++;
		}
		y--;
	}
}

void		count_indents(t_token *token)
{
	count_indent_left(token);
	count_indent_right(token);
	count_indent_up(token);
	count_indent_down(token);
}
