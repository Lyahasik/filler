/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:13:58 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 16:38:06 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	allocation_token(t_token *token)
{
	int	i;

	if (!(token->cells = (int**)malloc(sizeof(int*) * token->height)))
		return (0);
	i = -1;
	while (++i < token->height)
		token->cells[i] = NULL;
	i = -1;
	while (++i < token->height)
	{
		if (!(token->cells[i] = (int*)malloc(sizeof(int) * token->width)))
			return (0);
	}
	return (1);
}

static int	check_symbol_token(char c)
{
	if (c == '.')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

static int	fill_cells_token(t_token *token, char *line)
{
	int	i;
	int	j;

	if (!allocation_token(token))
		return (0);
	i = 0;
	while (i < token->height)
	{
		free(line);
		get_next_line(0, &line);
		j = 0;
		while (j < token->width)
		{
			token->cells[i][j] = check_symbol_token(*(line + j));
			j++;
		}
		i++;
	}
	free(line);
	return (1);
}

int	read_token(t_token *token, char *line)
{
	char	*number;

	number = ft_strchr(line, ' ');
	token->height = ft_atoi(number);
	number = ft_strchr(number + 1, ' ');
	token->width = ft_atoi(number);
	if (!(fill_cells_token(token, line)))
		return (0);
	count_indents(token);
	return (1);
}
