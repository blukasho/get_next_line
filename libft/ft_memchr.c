/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:26:45 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/07 17:02:51 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;

	src = (unsigned char *)s;
	ch = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (src[i] == ch)
			return (src + i);
	return (NULL);
}
