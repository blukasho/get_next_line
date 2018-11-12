/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/12 12:26:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			read_line(int fd, int *val)
{
	char		buf[BUFF_SIZE + 1];

	val = read(fd, buf, BUFF_SIZE);
	if (ft_strlen(buf))
		return (buf)
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static char	*res = "";
	char		*tmp;
	int			val;

	val = 1;
	while (val > 0)
	{
		if (ft_strlen(tmp))
		{
			if (!(res = ft_strjoin(res, tmp)))
				return (-1);
		}
		else
		{
			if (!(tmp = read_line(fd, &val)))
				return (-1);
		}
		ft_memdel(&tmp);
	}
	return (0);
}
