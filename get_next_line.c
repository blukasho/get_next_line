/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/26 15:58:48 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//del stdio.h
#include <stdio.h>

char				**read_line(char **cur, size_t *len, const int fd)
{
	char			*buf;
	char			*tmp;

	tmp = *cur;
	if ((buf = ft_strnew(BUFF_SIZE)))
	{
		if ((*len = read(fd, buf, BUFF_SIZE)) > 0)
			buf[*len] = '\0';
			if((*cur = ft_strjoin(*cur, buf)))
			{
				ft_strdel(&tmp);
				ft_strdel(&buf);
				return (cur);
			}
		ft_strdel(&buf);
		*len = -1;
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

int					get_next_line(const int fd, char **line)
{
	size_t			len;
	static	t_lst	*lst;
	char			**cur;

	len = 1;
	if (fd < 0 || (!lst && !get_str(&lst, fd)))
		return (-1);
	if ((cur = get_str(&lst, fd)))
	{
		if (!*cur && (*cur = ft_strnew(0)))
			while (len > 0)
				cur = read_line(cur, &len, fd);
		printf("%s", *cur);
	}
	//перезапись строки
	return (0);
}
