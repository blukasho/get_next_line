/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:13:49 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/15 00:19:46 by blukasho         ###   ########.fr       */
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

	fd = open(argv[1], O_RDONLY);
	while((val = get_next_line(fd, &res)))
	{
		ft_putstr(res);
		ft_putchar('\n');
		ft_putnbr(val);
		ft_putchar('\n');
		ft_strdel(&res);
	}
	return (0);
}
