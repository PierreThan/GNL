/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:21:02 by pthan             #+#    #+#             */
/*   Updated: 2018/12/27 17:21:09 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	int	i;

	if (!(s && charset))
		return (NULL);
	while (*s)
	{
		i = 0;
		while (charset[i])
			if (charset[i++] == *s)
				return (s);
		*s++;
	}
	return (NULL);
}
