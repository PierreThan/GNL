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
