/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:06:10 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/14 12:26:02 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	size;

	i = (n < 0) ? 2 : 1;
	size = n;
	while (n /= 10)
		i++;
	if (!(str = ft_strnew(i)))
		return (0);
	if (size < 0)
		str[0] = '-';
	if (size == 0)
		str[0] = '0';
	else
		while (--i)
		{
			str[i] = ((size < 0) ? -size : size) % 10 + '0';
			size = size / 10;
		}
	if (size > 0)
		str[i] = (size % 10) + '0';
	return (str);
}
