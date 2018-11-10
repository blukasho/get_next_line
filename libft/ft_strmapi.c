/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 12:44:07 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/07 16:53:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = -1;
	if (s && f)
	{
		res = ft_strnew(ft_strlen(s));
		if (res)
			while (s[++i])
				res[i] = f(i, s[i]);
		return (res);
	}
	return (NULL);
}
