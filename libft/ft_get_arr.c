/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:50:10 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/09 19:13:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_get_arr(size_t x, size_t y)
{
	char	**res;
	size_t	i;

	i = 0;
	if ((res = (char **)malloc(y * sizeof(char *))))
	{
		while (i < y)
			res[i++] = ft_strnew(x);
		res[y] = NULL;
	}
	return (res);
}
