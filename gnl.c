#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int	get_line(char **line, char **str)
{
	unsigned long	i;
	char			*tmp;

	i = 0;
	tmp = *str;
	while (str[0][i] && (str[0][i] != '\n' || str[0][i] != '\r'))
		i++;
	*line = ft_strsub(*str, 1, i);
	*line[i - 1] = '\0';
	if (str[0][i] && (str[0][i] == '\n' || str[0][i] == '\r'))
	{
	//	str[0][i] = '\0';
		i++;
	}
	if (!(*str = ft_strdup((*str + i))))
		return (-1);
	free(tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*res = NULL;
	long		r;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = res;
		if (tmp)
		{
			if (!(res = ft_strjoin(res, buff)))
				return (-1);
			free(tmp);
		}
		else
			res = ft_strdup(buff);
		if (ft_strchr(res, '\n'))
			return (get_line(line, &res));
	}
	if (ft_strlen(res) && r == 0)
		return (get_line(line, &res));
	if (r > 0)
		return (1);
	if (r < 0)
		return(-1);
	return (0);
}
