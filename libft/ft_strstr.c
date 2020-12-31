/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:19:52 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/04 17:27:45 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*test;
	char	*str;

	str = (char *)haystack;
	if (!*(needle))
		return ((char *)haystack);
	while (*(str))
	{
		i = 0;
		if (*(str) == *(needle))
		{
			test = (char *)str;
			while (*(str++) == needle[i] && needle[i])
				i++;
		}
		if (needle[i] == '\0')
			return (test);
		else if (i)
			str = ++test;
		str++;
	}
	return (0);
}
