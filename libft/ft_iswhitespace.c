////		HEADER HEADER HEADER HEADER

#include "libft.h"

int	ft_iswhitespace(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n' || c == '\r')
		|| (c == '\v' || c == '\f'))
		return (1);
	return (0);
}
