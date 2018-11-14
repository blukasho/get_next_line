/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/15 00:52:23 by blukasho         ###   ########.fr       */
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

	if (!(tmp = ft_strchr(*buf, '\n')))
	{
		ft_strdel(&*buf);
		return (NULL);
	}
	if (!(res = ft_strdup(++tmp)))
		return (NULL);
	ft_strdel(&*buf);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buf;
	int			val;

	val = 1;
	if (0 > fd || !line || (!buf && !(buf = ft_strnew(0))))
		return (-1);
	if (fd > 0 && val && !*buf)
		while (val > 0)
			buf = read_line(fd, &val, buf);
	if (*buf)
	{
		if (!(*line = ft_strndup(buf, ft_strlen_chr(buf, '\n'))))
			return (-1);
		buf = buf_rewrite(&buf);
		return (1);
	}
	ft_strdel(&buf);
	return (0);
}
