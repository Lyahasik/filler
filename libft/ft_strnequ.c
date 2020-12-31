/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:57:18 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/09 22:07:32 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*(str1) == *(str2) && *str1 && n--)
		if ((*(str1++) == *(str2++) && !(n - 1)))
			return (1);
	return ((*(str1) == *(str2)) ? 1 : 0);
}
