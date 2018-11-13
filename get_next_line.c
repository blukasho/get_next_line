/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/13 18:43:28 by blukasho         ###   ########.fr       */
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

int				get_next_line(const int fd, char **line)
{
	static char	*buf;
	int			val;

	val = 1;
	if (fd > 0 && val && (buf = ft_strnew(0)))
	{
		while (val > 0)
			buf = read_line(fd, &val, buf);
		if (buf)

		*line = ft_strdup(buf);
	}
	return (0);
}
