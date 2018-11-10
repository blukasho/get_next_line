/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:45:10 by blukasho          #+#    #+#             */
/*   Updated: 2018/11/08 10:19:24 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (f && lst)
	{
		tmp = f(lst);
		res = tmp;
		while (lst->next)
		{
			lst = lst->next;
			tmp->next = f(lst);
			if (tmp->next)
			{
				tmp = tmp->next;
			}
		}
		return (res);
	}
	return (NULL);
}
