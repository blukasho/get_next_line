/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:13:49 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/26 15:59:30 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		val;
	char	*res;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	val = get_next_line(fd, &res);
	printf("val = %d\n", val);
	val = get_next_line(fd2, &res);
	printf("val = %d\n", val);
	return (0);
}
