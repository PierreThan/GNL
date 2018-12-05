/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:43:42 by pthan             #+#    #+#             */
/*   Updated: 2018/11/20 15:50:13 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if (c < 97 || c > 122)
		return (0);
	return (1);
}

static int	ft_isupper(int c)
{
	if (c < 65 || c > 90)
		return (0);
	return (1);
}

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
