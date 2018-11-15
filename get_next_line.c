/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/15 19:14:37 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char			*buf_rewrite(char **buf)
{
	char		*tmp;
	char		*res;

	if ((tmp = ft_strchr(*buf, '\n')))
	{
		res = ft_strdup(++tmp);
		ft_strdel(&*buf);
		return (res);
	}
	else if ((res = ft_strdup(*buf)))
	{
		ft_strdel(&*buf);
		return (res);
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buf;
	int			val;

	val = 1;
	if (fd < 0 || !line || (!buf && !(buf = ft_strnew(0))))
		return (-1);
	if (fd > 0 && val > 0 && !*buf)
		while (val > 0)
			buf = read_line(fd, &val, buf);
	if (val < 0)
		return (-1);
	if (buf[ft_strlen_chr(buf, '\n')] != '\0')
	{
		*line = ft_strndup(buf, ft_strlen_chr(buf, '\n'));
		buf = buf_rewrite(&buf);
		return (1);
	}
	else if (buf[0] && buf[1])
	{
		*line = ft_strdup(buf);
		buf[0] = '\0';
		return (1);
	}
	ft_strdel(&buf);
	return (0);
}
