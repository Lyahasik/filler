/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:18:36 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/23 18:44:59 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_help(char ***mass, char *str, int ch, char c)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= ch - 1)
	{
		j = 0;
		while (str[j] != c && str[j])
			j++;
		if (!((*mass)[i] = ft_strnew(j)))
		{
			while (**mass)
			{
				free(**mass);
				**mass = NULL;
				(*mass)++;
			}
			return ;
		}
		ft_strncpy((*mass)[i], str, j);
		str = str + j;
		while (*str == c)
			str++;
	}
	(*mass)[i] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**mass;
	char	*str;
	int		ch;

	if (!s || !(str = ft_strctrim(s, c)))
		return (0);
	ch = ft_sepchar(str, c) + 1;
	if (!*str)
		ch--;
	if (!(mass = (char **)malloc((ch + 1) * sizeof(char *))))
		return (0);
	ft_help(&mass, str, ch, c);
	free(str);
	return (mass);
}
