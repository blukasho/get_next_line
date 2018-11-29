/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:38:41 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/29 12:43:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	char	*res;

	if (argc)
	{
		fd = open(argv[1], O_RDONLY);

		while (get_next_line(fd, &res) > 0)
			printf("%s\n", res);
	}
	return (0);
}
