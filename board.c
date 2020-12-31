/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:40:33 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 12:03:00 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_symbol_board(t_board *board, char c)
{
	if (c == '.')
	{
		return (-1);
	}
	else if (board->player == c)
	{
		return (0);
	}
	else
	{
		return (1000);
	}
}

int	allocation_board(t_board *board)
{
	int	i;

	if (!(board->cells = (int**)malloc(sizeof(int*) * board->height)))
		return (0);
	i = -1;
	while (++i < board->height)
		board->cells[i] = NULL;
	i = -1;
	while (++i < board->height)
	{
		if (!(board->cells[i] = (int*)malloc(sizeof(int) * board->width)))
		{
			return (0);
		}
	}
	return (1);
}

static int	fill_cells_board(t_board *board, char *line, int fd, FILE *file)
{
	int	i;
	int	j;

	if (!allocation_board(board))
		return (0);
	i = -1;
	while (++i < board->height)
	{
		line = next_line(line, fd);
		// fputs(ft_strjoin(line, "\n"), file);
		j = -1;
		while (++j < board->width)
		{
			board->cells[i][j] = check_symbol_board(board, *(line + j + 4));
		}
		free(line);
	}
	return (1);
}

int		read_board(t_board *board, char *line, int fd, FILE *file)
{
	char	*number;

	//printf("%s\n", line);
	// parametrs = ft_strsplit(line + 7, ' ');
	number = ft_strchr(line, ' ');
	board->height = ft_atoi(number);
	number = ft_strchr(number + 1, ' ');
	board->width = ft_atoi(number);
	line = next_line(line, fd);
	// fputs(ft_strjoin(line, "\n"), file);
	// fputs(ft_strjoin(ft_itoa(board->height), ft_itoa(board->width)), file);
	// fputs("\n", file);
	if (!fill_cells_board(board, line, fd, file))
		return (0);
	// write(1, "read_board\n", 12);
	heat_map(board, file);
	return (1);
}
