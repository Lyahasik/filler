/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:05:27 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/24 18:02:48 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (!*(str1) && !*(str2))
			return (0);
		if (*(str1) > *(str2))
			return (*(str1) - *(str2));
		if (*(str1++) < *(str2++))
			return (*(--str1) - *(--str2));
	}
	return (0);
}
