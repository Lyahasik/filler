/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:18:36 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/07 20:13:20 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = NULL;
	while (*(s))
	{
		if (*(s) == c)
			str = (char *)s;
		s++;
	}
	if (*(s) == c)
		str = (char *)s;
	return ((c > 127 || c < 0 || !str) ? 0 : str);
}
