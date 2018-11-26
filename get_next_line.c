/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/26 10:33:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//del stdio.h
#include <stdio.h>

char				**read_line(t_lst **cur, const int fd, size_t *len)
{
	char			*buf;
	char			*tmp;

	tmp = (*cur)->str;
	if ((buf = ft_strnew(BUFF_SIZE)))
	{
		if ((*len = read(fd, buf, BUFF_SIZE)) > 0)
			buf[*len] = '\0';
			if(((*cur)->str = ft_strjoin((*cur)->str, buf)))
			{
				ft_strdel(&tmp);
				ft_strdel(&buf);
				return (NULL);
			}
		ft_strdel(&buf);
		*len = -1;
	}
	return (NULL);
}	

t_lst				**crt_lst_elem(t_lst **lst, const int fd)
{
	
}

t_lst				**get_lst_elem(t_lst **lst, const int fd)
{
	t_lst			*tmp;

	if (!*lst)
	{
		if ((*lst = (t_lst *)malloc(sizeof(t_lst))))
		{
			if (((*lst)->str = ft_strnew(0)))
			{
				(*lst)->fd = fd;
				(*lst)->next = NULL;
				return (lst);
			}
			free((*lst)->str);
		}
		return (NULL);
	}
//	tmp = *lst;
	while (*lst)
	{
		if ((*lst)->fd == fd)
			return (&*lst);
		*lst = (*lst)->next;
	}
}

int					get_next_line(const int fd, char **line)
{
	size_t			len;
	static	t_lst	*lst;
	t_lst			**cur;

	len = 1;
	if (fd < 0 || (!lst && !get_lst_elem(&lst, fd)))
		return (-1);
	if ((cur = get_lst_elem(&lst, fd)))//проверить не адрес а указатель
	{
		while (len > 0)
			read_line(cur, fd, &len);
		if (len == -1)
			return (-1);
	}
	//перезапись строки
	return (0);
}
