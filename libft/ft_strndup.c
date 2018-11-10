/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:49:32 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/09 18:34:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	res = ft_strnew(n);
	if (res)
		while (i < n)
		{
			res[i] = s1[i];
			i++;
		}
	return (res);
}
