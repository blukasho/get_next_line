/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/23 17:58:58 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//del stdio.h
#include <stdio.h>

char				*read_line(const int fd, char *res, size_t *len)
{
	char			*buf;
	char			*tmp;

	tmp = res;
	if ((buf = ft_strnew(BUFF_SIZE)))
	{
		if ((*len = read(fd, buf, BUFF_SIZE)) > 0)
			buf[*len] = '\0';
			if((res = ft_strjoin(res, buf)))
			{
				ft_strdel(&tmp);
				ft_strdel(&buf);
				return (res);
			}
		ft_strdel(&buf);
	}
	return (NULL);
}	

char				*check_lst(t_lst *lst, const int fd)
{
	t_lst			*tmp;

	tmp = lst;
	while (lst)
	{
		printf("fd %d\n", fd);
		if (fd == lst->fd)
		{
			return (lst->str);
		}
		lst = lst->next;
	}
	return (NULL);
}

int					get_next_line(const int fd, char **line)
{
	size_t			len;
	char			*str;
	static	t_lst	*lst;
	int				ld;

	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->str = ft_strnew(0);
	lst->fd = fd;
	lst->str = read_line(fd, lst->str, &len);
	lst->next = NULL;
		
	printf("%s\n", check_lst(lst, fd));
	ft_strdel(&lst->str);
	printf("%s\n", check_lst(lst, fd));
	return (len);
}
