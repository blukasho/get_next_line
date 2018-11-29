/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:01:48 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/29 17:25:08 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int			main(int argc, char **argv)
{
	char	*res;
	int		fd;

	if (argc)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &res) > 0)
			printf("%s\n", res);
	}
	return (0);
}
