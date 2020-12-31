/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:07:13 by dhorker           #+#    #+#             */
/*   Updated: 2019/02/13 13:51:05 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int number)
{
	int	i;

	i = 1;
	if (number < 0)
	{
		if (number == -2147483648)
		{
			number /= 10;
			i++;
		}
		number = -number;
	}
	while (number > 9)
	{
		number /= 10;
		i++;
	}
	return (i);
}
