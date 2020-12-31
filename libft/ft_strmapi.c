/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:45:25 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 19:18:55 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*begin;
	char	i;

	if (!s)
		return (0);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (0);
	i = 0;
	begin = (char *)str;
	while (*s)
		*str++ = f(i++, *(s++));
	*str = '\0';
	return (begin);
}
