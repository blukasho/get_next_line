/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 12:17:45 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/07 16:55:54 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	const char	*res;
	char		*str;

	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			res = str;
			while (*s)
			{
				*str = f(*s);
				s++;
				str++;
			}
			return ((char *)res);
		}
	}
	return (NULL);
}
