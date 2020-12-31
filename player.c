/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:28:20 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/31 15:46:07 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	identify_player(char *player)
{
	char	*line;

	get_next_line(0, &line);
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
