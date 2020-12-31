/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:11:39 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/09 14:20:34 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;

	if (!size)
		return (ft_strlen(src));
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	i = (int)ft_strlen(dst);
	size = (i < (int)size) ? (int)size - i : 1;
	dst = &dst[ft_strlen(dst)];
	while (*src)
	{
		if (size == 1)
			*dst = '\0';
		else if (size--)
			*dst++ = *src;
		i++;
		src++;
	}
	*dst = '\0';
	return (i);
}
