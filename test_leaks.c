/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 10:46:53 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/25 13:20:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void		del_lst(t_lst **lst)
{
	free((*lst)->str);
	free(&**lst);
}

int			test_leaks(void)
{
	t_lst	*lst;
	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->str = (char *)malloc(10 * sizeof(char));
	del_lst(&lst);
	return(0);
}

int		main(void)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(10 * sizeof(char));

	str[9] = '\0';
	while (i < 10)
		str[i++] = 'A';
	printf("%s\n", str);
	free(str);
	printf("%s\n", str);
	return(0);
}
