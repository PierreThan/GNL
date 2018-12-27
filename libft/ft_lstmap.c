/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:19:38 by pthan             #+#    #+#             */
/*   Updated: 2018/12/27 17:19:40 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp1;
	t_list	*tmp2;

	if (!f || !lst)
		return (NULL);
	res = f(lst);
	tmp1 = res;
	tmp2 = res;
	lst = lst->next;
	while (lst)
	{
		tmp1 = f(lst);
		tmp2->next = tmp1;
		tmp2 = tmp1;
		lst = lst->next;
	}
	return (res);
}
