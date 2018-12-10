#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

static t_gnl	*add_file(int fd, t_gnl *lst)
{
	t_gnl	*res;

	res = NULL;
	if (!lst)
	{
		if (!(lst = (t_gnl*)malloc(sizeof(*lst))) || !(lst->line = ft_strnew(BUFF_SIZE)))
			return (NULL);
		if (read(fd, lst->line, BUFF_SIZE) == -1)
			return (NULL);
		lst->fd = fd;
		return  (lst);
	}
	else
	{
		while (lst->next)
			lst = lst->next;
		if (!(res = add_file(fd, res)))
			return (NULL);
		lst->next = res;
		return (res);
	}
}


t_gnl			*get_file(int fd, t_gnl *lst)
{
	t_gnl	*tmp;

	tmp = lst;
	if (!lst)
		return (add_file(fd, lst));
	while (lst)
	{
		if (lst->fd == fd)
		{
			if (!lst->line)
				if (!(lst->line = ft_strnew(BUFF_SIZE)))
					return (NULL);
			return (lst);
		}
		lst = lst->next;
	}
	return (add_file(fd, tmp));
}

static int		get_line(t_gnl *lst, char **line)
{
	char	*buff;
	int		r;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	r = 0;
	while (!ft_strchr(lst->line, '\n') && (r = read(lst->fd, buff, BUFF_SIZE)) >= 0)
	{
		if (!(lst->line = ft_strjoin(lst->line, buff)))
			return (-1);
		if (r == 0)
			break;
	}
	if (r >= 0)
		*line = ft_strsep(&lst->line, "\n");
	free(buff);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*tmp;
	int				r;

	if (fd < 0 || !line || (r = read(fd, *line, 0) < 0))
		return (-1);
	r = 0;
	if (!lst)
	{
		lst = add_file(fd, lst);
		r = get_line(lst, line);
	}
	else
	{
		tmp = get_file(fd, lst);
		r = get_line(tmp, line);
	}
	return (r);
}
