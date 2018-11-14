/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:56:28 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/14 14:29:18 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen_chr(const char *s, char c)
{
	const char	*tmp;

	tmp = s;
	if (s)
		while (*s && *s != c)
			++s;
	return (s - tmp);
}
