/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:14:14 by dhorker           #+#    #+#             */
/*   Updated: 2020/12/31 15:45:54 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	char	*line;
	t_board	board;
	t_token	token;

	identify_player(&board.player);
	while (get_next_line(0, &line))
	{
		if (!read_board(&board, line))
			break ;
		get_next_line(0, &line);
		if (!read_token(&token, line)
			|| !insert_token(&board, &token))
			break ;
		free_board(&board);
		free_token(&token);
	}
	free_board(&board);
	free_token(&token);
	return (0);
}
