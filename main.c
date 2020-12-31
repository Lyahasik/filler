/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:14:14 by dhorker           #+#    #+#             */
/*   Updated: 2020/12/31 11:50:02 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	temperature_drop(t_board *board, t_vector2 enemy);

void	output_board(t_board *board, FILE *file)
{
	int i = 0;
	while (i < board->height)
	{
		fputs(ft_strjoin(ft_itoa(i), "\t"), file);
		int j = 0;
		while (j < board->width)
		{
			fputs(ft_strjoin(ft_itoa(board->cells[i][j]), "\t"), file);
			// printf("%4d ", board->cells[i][j]);
			j++;
		}
		// printf("\n");
		fputs("\n", file);
		i++;
	}
	// printf("\n");
	fputs("\n", file);
}

void	output_token(t_token *token, FILE *file)
{
	int i = 0;
	while (i < token->height)
	{
		int j = 0;
		while (j < token->width)
		{
			// write(1, ft_itoa(token->cells[i][j]), ft_strlen(ft_itoa(token->cells[i][j])));
			fputs(ft_itoa(token->cells[i][j]), file);
			j++;
		}
		// write(1, "\n", 1);
		fputs("\n", file);
		i++;
	}
	// fputs("\n", file);
	// fputs("\n", file);
	// i = token->indent_up;
	// while (i < token->height - token->indent_down)
	// {
	// 	int j = token->indent_left;
	// 	while (j < token->width - token->indent_right)
	// 	{
	// 		fputs(ft_itoa(token->cells[i][j]), file);
	// 		j++;
	// 	}
	// 	fputs("\n", file);
	// 	i++;
	// }
}

int		main()
{
	char	*line;
	t_board	board;
	t_token	token;

	FILE *file = fopen("test.txt", "w");
	identify_player(&board.player, 0);
	int i = -1;
	while (get_next_line(0, &line))
	{
		// fputs(ft_strjoin(line, "\n"), file);
		if (!read_board(&board, line, 0, file))
		{
			fputs("read_board\n", file);
			break ;
		}
		line = next_line(line, 0);
		if (!read_token(&token, line, 0, file))
		{
			fputs("read_token\n", file);
			break ;
		}
		if (!insert_token(&board, &token, file))
			break ;
		free_board(&board);
		free_token(&token);
	}
	free_board(&board);
	free_token(&token);
	fclose(file);
	return (0);
}

// int	main(int av, char **ac)
// {
// 	char	*line;
// 	t_board	board;
// 	t_token	token;

// 	line = NULL;
// 	if (av == 2)
// 	{
// 		int fd = open(ac[1], O_RDONLY);
// 		FILE *file = fopen("test.txt", "w");
// 		identify_player(&board.player, fd);
// 		int i = -1;
// 		while (get_next_line(fd, &line))
// 		{
// 			// fputs(ft_strjoin(line, "\n"), file);
// 			if (!read_board(&board, line, fd, file))
// 			{
// 				fputs("read_board\n", file);
// 				break ;
// 			}
// 			// write(1, line, ft_strlen(line));
// 			line = next_line(line, fd);
// 			if (!read_token(&token, line, fd, file))
// 			{
// 				fputs("read_token\n", file);
// 				break ;
// 			}
// 			if (!insert_token(&board, &token, file))
// 				break ;
// 			free_board(&board);
// 			free_token(&token);
// 		}
// 		// free(line);
// 		fclose(file);
// 	}
// 	return (0);
// }
