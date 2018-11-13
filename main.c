/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:13:49 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/12 16:59:35 by blukasho         ###   ########.fr       */
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

	if (argc == 1)
	{
		ft_putstr("No filename!\n");
		return (0);
	}
	else if (argc > 2)	
	{
		ft_putstr("To many arguments!\n");
		return (0);
	}
	else if (argc == 2)
	{
		ft_putstr("Read file... \"");
		ft_putstr(argv[1]);
		ft_putstr("\"\n");
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("Cant open file...\n");
			return (0);
		}
		else
		{
			if ((val = get_next_line(fd, &res)))
			{
				ft_putstr(res);
				ft_putchar('\n');
			}
		}
	}
	if (0 > close(fd))
		ft_putstr("Cant close file.\n");
	else
		ft_putstr("File close successfully.\n");
	return (0);
}
