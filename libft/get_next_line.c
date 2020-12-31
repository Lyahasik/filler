/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:32:33 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/12 18:53:08 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			correct(t_list **gnl, char *mass, int size)
{
	char			*corr;

	corr = (*gnl)->content;
	if (size < 0)
	{
		ERR(((*gnl)->content = ft_strjoin((*gnl)->content, mass)));
	}
	else
		ERR(((*gnl)->content = ft_strsub((*gnl)->content, size,
		ft_strlen((*gnl)->content) - size)));
	ft_strdel(&corr);
	return (1);
}

static int			get_next_cont(t_list *gnl, char *mass, char **line, int fd)
{
	int				size;
	int				i;

	i = 1;
	size = -1;
	while (!(ft_strchr(gnl->content, '\n')) && i != 0)
	{
		if ((i = read(fd, mass, BUFF_SIZE)) == -1)
			return (-1);
		mass[i] = '\0';
		END((correct(&gnl, mass, size)));
	}
	ERR(((char*)gnl->content)[0]);
	size = ((ft_strchr(gnl->content, '\n')) - (char *)gnl->content);
	END((*line = (i == 0) ? ft_strdup(gnl->content)
		: ft_strsub(gnl->content, 0, size)));
	if (i == 0)
		ft_bzero(gnl->content, ft_strlen(gnl->content));
	else
		END((correct(&gnl, mass, size + 1)));
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*gnl;
	t_list			*start;
	char			mass[BUFF_SIZE + 1];
	int				i;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (!gnl)
	{
		ERR((gnl = ft_lstnew("", 1)));
		gnl->content_size = fd;
	}
	start = gnl;
	while (start->next && start->content_size != (size_t)fd)
		start = start->next;
	if (start->content_size != (size_t)fd)
	{
		END((start = ft_lstnew("", 1)));
		start->content_size = fd;
		ft_lstadd(&gnl, start);
	}
	if ((i = get_next_cont(start, mass, line, fd)) == 0)
		ft_lstdelcut(&gnl, &start);
	return (i);
}
