/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:24:55 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/23 13:58:37 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*begin;

	if (!s || !f)
		return (0);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (0);
	begin = (char *)str;
	while (*s)
		*str++ = f(*(s++));
	*str = '\0';
	return (begin);
}
