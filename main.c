/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:13:49 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/14 15:05:48 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	int		val;
	char	*res;
	char	*res2;

	val = 0;
	fd = open(argv[1], O_RDONLY);
	while (val < 3)
	{
		get_next_line(fd, &res);
//		ft_putstr(res);
//		ft_putchar('\n');
		++val;
	}
	return (0);
}
