/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:48:43 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 19:30:44 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (dst == src)
		return (dst);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str1 <= str2)
		while (len--)
			*(str1++) = *(str2++);
	else
	{
		str1 = str1 + len - 1;
		str2 = str2 + len - 1;
		while (len--)
			*(str1--) = *(str2--);
	}
	return (dst);
}
