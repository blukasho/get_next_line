/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/14 18:59:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*
 * del stdio.h
 */
char			*read_line(int fd, int *val, char *res)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	tmp = res;
	*val = read(fd, buf, BUFF_SIZE);
	buf[*val] = '\0';
	if (!(res = ft_strjoin(res, buf)))
		return (NULL);
	ft_strdel(&tmp);
	return (res);
}

void			buf_rewrite(char **buf)
{
	char		*tmp;

	tmp = ft_strchr(*buf, '\n');
	ft_strcpy(*buf, ++tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buf;
	int			val;

	val = 1;
	if (!buf)
		buf = ft_strnew(0);
	if (fd > 0 && val)
	{
		if (buf[0] == '\0')
			while (val > 0)
				buf = read_line(fd, &val, buf);
	}
	if (buf[0] != '\0')
	{
		*line = ft_strndup(buf, ft_strlen_chr(buf, '\n'));
		buf_rewrite(&buf);
		return(1);
	}
	return (0);
}
