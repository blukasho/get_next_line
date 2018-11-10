/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:54:26 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/08 12:19:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word_cp(char const *s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	res = ft_strnew(i);
	i = 0;
	if (res)
	{
		while (s[i] != c && s[i])
		{
			res[i] = s[i];
			i++;
		}
		return (res);
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**res;

	if (s)
	{
		i = ft_count_words(s, c);
		res = (char **)malloc(++i * sizeof(char *));
		if (res && !(i = 0))
		{
			while (*s)
			{
				if (*s != c)
				{
					res[i++] = word_cp(s, c);
					while (*s != c && *s)
						s++;
					s--;
				}
				s++;
			}
			res[i] = NULL;
			return (res);
		}
	}
	return (NULL);
}
