/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:07:27 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/07 17:35:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
					const void *restrict src, int c, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;
	unsigned char	ch;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = -1;
	ch = (unsigned char)c;
	while (++i < n)
	{
		ds[i] = sr[i];
		if (ch == sr[i])
			return (dst + (++i));
	}
	return (NULL);
}
