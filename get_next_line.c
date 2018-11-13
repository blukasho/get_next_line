/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/12 19:22:39 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*read_line(int fd, int *val, char *res)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	tmp = res;
	*val = read(fd, buf, BUFF_SIZE);
	if (!(res = ft_strjoin(res, buf))
			return (NULL);
	ft_strdel(&tmp);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static char *buf;
	int			val;

	val = 1;
	if (fd > 0 && line)
	{
		while (val > 0)
		{
			buf = read_line(fd, &val, buf);
		}
		return (0);
	}
	return (-1);
}
