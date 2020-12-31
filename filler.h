/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:00:40 by dhorker           #+#    #+#             */
/*   Updated: 2020/12/31 16:34:50 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_vector2
{
	int			x;
	int			y;
}				t_vector2;

typedef struct	s_board
{
	char		player;
	int			height;
	int			width;
	int			**cells;
}				t_board;

typedef struct	s_token
{
	t_vector2	begin;
	t_vector2	suitable_point;
	int			min;
	int			check;
	int			height;
	int			width;
	int			**cells;
	int			indent_left;
	int			indent_right;
	int			indent_up;
	int			indent_down;
}				t_token;

/*
** Player
*/

void			identify_player(char *player);

/*
** Board
*/

int				read_board(t_board *board, char *line);

/*
** Heat_map
*/

void			heat_map(t_board *board);

/*
** Token
*/

int				read_token(t_token *token, char *line);

/*
** Indents
*/

void			count_indents(t_token *token);

/*
** Freeing
*/

int				free_token(t_token *token);
int				free_board(t_board *board);

/*
** Insert
*/

int				insert_token(t_board *board, t_token *token);

#endif
