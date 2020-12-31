/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:28:20 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/30 20:24:59 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	identify_player(char *player, int fd)
{
	char	*line;

	get_next_line(fd, &line);
	// fputs(ft_strjoin(line, "\n"), file);
	if (ft_strstr(line, "dhorker.filler"))
	{
		if (ft_strstr(line, "p1"))
		{
			*player = 'O';
		}
		else
		{
			*player = 'X';
		}
	}
	free(line);
}
