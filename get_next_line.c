/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/25 17:36:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//del stdio.h
#include <stdio.h>

char				**read_line(const int fd, char **res, size_t *len)
{
	char			*buf;
	char			*tmp;

	tmp = *res;
	if ((buf = ft_strnew(BUFF_SIZE)))
	{
		if ((*len = read(fd, buf, BUFF_SIZE)) > 0)
			buf[*len] = '\0';
			if((*res = ft_strjoin(*res, buf)))
			{
				ft_strdel(&tmp);
				ft_strdel(&buf);
				return (res);
			}
		ft_strdel(&buf);
	}
	return (NULL);
}	

t_lst				**cr_new_elem(t_lst **lst, const int fd)
{
	t_lst			*n_lst;
	t_lst			*tmp;

	tmp = *lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	if ((n_lst = (t_lst *)malloc(sizeof(t_lst))))
	{
		if ((n_lst->str = ft_strnew(0)))
		{
			n_lst->fd = fd;
			n_lst->next = NULL;
			(*lst)->next = n_lst;
			*lst = tmp;
			return (lst);	
		}
		free(n_lst);
	}
	return(NULL);
}

char				**check_lst(t_lst **lst, const int fd)
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
				return(&((*lst)->str));
			}
			free(&*lst);
			return (NULL);
		}
	}
	while (*lst)
	{
		if ((*lst)->fd == fd)
			return (&((*lst)->str));
		*lst = (*lst)->next;
	}
	return (NULL);
}

int					get_next_line(const int fd, char **line)
{
	size_t			len;
	char			**str;
	static	t_lst	*lst;
	int				ld;
	char			**tmp;

	printf("lst = %d\n", lst);
	if (fd < 0 || (!lst && !check_lst(&lst, fd)))
		return (-1);
	printf("lst = %d\n", lst);
//	cr_new_elem(&lst, fd);
//	str = read_line(fd, str, &len);

//	tmp = check_lst(&lst, fd);
//	printf("%s\n", *tmp);
	free(lst->str);
	free(&*lst);
	return (0);
}
