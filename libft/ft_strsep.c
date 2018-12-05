#include "libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*res;
	int	i;
	
	if (!(*stringp && delim))
		return (NULL);
	res = *stringp;
	if (**stringp == '\n' && !ft_strchr(delim, '\n'))
	{
		*((*stringp)++) = '\0';
		return (res);
	}
	while (**stringp)
	{
		i = 0;
		while (delim[i])
		{
			if (delim[i++] == **stringp)
			{
				*((*stringp)++) = '\0';
				return (res);
			}
		}
		(*stringp)++;
	}
	return (res);
}
