/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memspy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:55:28 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/07 17:03:17 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*sr;
	char	*ds;

	sr = (char *)src;
	ds = (char *)dst;
	i = -1;
	while (++i < n)
		ds[i] = sr[i];
	return (dst);
}
