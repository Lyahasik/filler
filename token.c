/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:13:58 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 12:03:15 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	allocation_token(t_token *token)
{
	int	i;

	if (!(token->cells = (int**)malloc(sizeof(int*) * token->height)))
		return (0);
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

static int	fill_cells_token(t_token *token, char *line, int fd, FILE *file)
{
	int	i;
	int	j;

	if (!allocation_token(token))
		return (0);
	i = 0;
	while (i < token->height)
	{
		line = next_line(line, fd);
		// fputs(ft_strjoin(line, "\n"), file);
		j = 0;
		while (j < token->width)
		{
			token->cells[i][j] = check_symbol_token(*(line + j));
			j++;
		}
		i++;
		free(line);
	}
	//output_token(token);
	return (1);
}

int	read_token(t_token *token, char *line, int fd, FILE *file)
{
	char	*number;

	// write(1, line, ft_strlen(line));
	// write(1, "\n", 1);
	number = ft_strchr(line, ' ');
	// write(1, number, ft_strlen(number));
	token->height = ft_atoi(number);
	number = ft_strchr(number + 1, ' ');
	// write(1, number, ft_strlen(number));
	token->width = ft_atoi(number);
	// fputs(ft_strjoin(line, "\n"), file);
	// fputs(ft_strjoin(ft_itoa(token->height), ft_itoa(token->width)), file);
	// fputs("\n", file);
	// write(1, "read_token_1\n", 14);
	if (!(fill_cells_token(token, line, fd, file)))
		return (0);
	// write(1, "read_token_2\n", 14);
	count_indents(token);
	// write(1, "read_token_3\n", 14);
	// output_token(token, file);
	/*printf("%d\n", token->indent_left);
	printf("%d\n", token->indent_right);
	printf("%d\n", token->indent_up);
	printf("%d\n", token->indent_down);*/
}
