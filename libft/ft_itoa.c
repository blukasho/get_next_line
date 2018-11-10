/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:46:40 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/07 17:33:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(int n)
{
	int		res;

	res = 0;
	while (n)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		min;
	int		len;

	min = 0;
	if (n < 0)
		min = 1;
	len = count_int(n) + min;
	res = ft_strnew((len > 0 ? len : ++len));
	if (res)
	{
		while (--len >= 0)
		{
			res[len] = (n < 0 ? -(n % 10) : (n % 10)) + '0';
			n = n / 10;
		}
		if (min)
			res[0] = '-';
	}
	return (res);
}
