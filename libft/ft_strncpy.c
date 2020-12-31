/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:14:36 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/06 14:59:19 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *str1;

	str1 = dst;
	while (len--)
	{
		if (*(src))
			*(str1++) = *(src++);
		else
			*(str1++) = '\0';
	}
	return (dst);
}
