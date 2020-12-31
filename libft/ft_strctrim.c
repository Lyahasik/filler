/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:24:50 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 15:27:16 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	while (*s == c)
		s++;
	i = ft_strlen(s) - 1;
	if (!ft_strlen(s))
		return (!(str = ft_strnew(++i))) ? 0 : str;
	while (s[i] == c)
		i--;
	if (!(str = ft_strnew(++i)))
		return (0);
	while (--i)
		str[i] = s[i];
	str[i] = s[i];
	return (str);
}
