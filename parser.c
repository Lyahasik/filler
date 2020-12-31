/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:43:11 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 11:45:16 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*next_line(char *line, int fd)
{
	char	*new_line;

	free(line);
	get_next_line(fd, &new_line);
	return (new_line);
}
