/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/28 13:10:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				**read_line(char **cur, int *len, const int fd)
{
	char			*buf;
	char			*tmp;

	if ((buf = ft_strnew(BUFF_SIZE)))
	{
		if ((*len = read(fd, buf, BUFF_SIZE)) > 0)
		{
			tmp = *cur;
			buf[*len] = '\0';
			if ((*cur = ft_strjoin(*cur, buf)))
			{
				ft_strdel(&tmp);
				ft_strdel(&buf);
				return (cur);
			}
		}
		free(buf);
		return (cur);
	}
	return (NULL);
}

char				**crt_lst_elem(t_lst **lst, const int fd)
{
	t_lst			*new;

	if ((new = (t_lst *)malloc(sizeof(t_lst))))
	{
		new->str = NULL;
		new->fd = fd;
		new->next = *lst;
		*lst = new;
		return (&(*lst)->str);
	}
	return (NULL);
}

char				**get_str(t_lst **lst, const int fd)
{
	t_lst			*tmp;

	if (!*lst)
	{
		if ((*lst = (t_lst *)malloc(sizeof(t_lst))))
		{
			(*lst)->fd = fd;
			(*lst)->str = NULL;
			(*lst)->next = NULL;
			return (&(*lst)->str);
		}
		return (NULL);
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (&tmp->str);
		tmp = tmp->next;
	}
	return (crt_lst_elem(lst, fd));
}

void				cpy_line(char **cur, char **line)
{
	char			*tmp;
	size_t			nl;

	tmp = *cur;
	if (ft_strlen(*cur) == (nl = ft_strlen_chr(*cur, '\n')))
	{
		*line = ft_strdup(*cur);
		*cur = ft_strnew(0);
		free(tmp);
	}
	else
	{
		*line = ft_strndup(*cur, nl);
		*cur = ft_strdup(*cur + ++nl);
		free(tmp);
	}
}

int					get_next_line(const int fd, char **line)
{
	int				len;
	static t_lst	*lst;
	char			**cur;

	len = 1;
	if (fd < 0 || BUFF_SIZE <= 0 || (!lst && !get_str(&lst, fd)))
		return (-1);
	cur = get_str(&lst, fd);
	if (!*cur && (*cur = ft_strnew(0)))
		while (len > 0)
			cur = read_line(cur, &len, fd);
	if (len < 0)
	{
		ft_strdel(cur);
		return (-1);
	}
	if (*cur[0] == '\0' && !(*line = NULL))
	{
		ft_strdel(cur);
		return (0);
	}
	cpy_line(cur, line);
	return (1);
}
