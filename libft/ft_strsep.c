/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:21:19 by pthan             #+#    #+#             */
/*   Updated: 2018/12/27 17:25:41 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_init_strsep(char **stringp, const char *delim)
{
	int	j;

	if (*delim == '\n' && *(delim + 1) == '\0')
	{
		if (**stringp == '\n')
		{
			**stringp = '\0';
			(*stringp)++;
			return (1);
		}
		else if (!ft_strchr(*stringp, '\n'))
		{
			j = ft_strlen(*stringp);
			*stringp += ft_strlen(*stringp);
			return (1);
		}
	}
	return (0);
}

char	*ft_strsep(char **stringp, const char *delim)
{
	int		i;
	char	*res;

	if (!(*stringp && delim))
		return (NULL);
	res = *stringp;
	if (ft_init_strsep(stringp, delim))
		return (res);
	while (**stringp)
	{
		i = 0;
		while (delim[i])
		{
			if (delim[i++] == **stringp)
			{
				**stringp = '\0';
				*stringp += 1;
				return (res);
			}
		}
		*stringp += 1;
	}
	return (res);
}
