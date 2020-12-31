/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:54 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 15:26:46 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	i = ft_strlen(s) - 1;
	if (!ft_strlen(s))
		return (!(str = ft_strnew(++i))) ? 0 : str;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i--;
	if (!(str = ft_strnew(++i)))
		return (0);
	while (--i)
		str[i] = s[i];
	str[i] = s[i];
	return (str);
}
