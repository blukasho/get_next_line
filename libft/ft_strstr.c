/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 10:27:33 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/07 16:45:42 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	int		r;

	r = 0;
	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*haystack)
	{
		while (needle[i])
		{
			if (needle[i] != haystack[i])
				r = 1;
			i++;
		}
		if (r == 0)
			return ((char *)haystack);
		i = 0;
		r = 0;
		haystack++;
	}
	return (NULL);
}
