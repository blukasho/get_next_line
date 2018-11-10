/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:18:41 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/07 13:51:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	beg;
	char	*res;

	beg = 0;
	if (s && 0 < (len = ft_strlen(s)))
	{
		while ((s[len - 1] >= 1 && s[len - 1] <= 19) || s[len - 1] == 32)
			--len;
		while ((s[beg] >= 1 && s[beg] <= 19) || s[beg] == 32)
			++beg;
		res = ft_strnew(len - beg);
		if (len == 0)
			return (ft_strdup("\0"));
		if (res)
		{
			while (len-- > beg)
				res[len - beg] = s[len];
			return (res);
		}
		return (res);
	}
	return ((char *)s);
}
