#include "libft/libft.h"
#include "get_next_line.h"

static t_file	*create_file(int fd, t_file *f)
{
	char	buff[BUFF_SIZE + 1];
	int	r;
	char	*tmp;

	if (f && f->fd == -2)
	{
		f->fd = fd;
		if (!(f->line = ft_strnew(1)))
			return (NULL);
		while ((r = read(fd, buff, BUFF_SIZE)))
		{
			buff[r] = '\0';
			tmp = f->line;
			if (!(f->line = ft_strjoin(f->line, buff)))
				return (NULL);
			free(tmp);
		}
		f->next  = NULL;
		return (f);
	}
	if (!(f = (t_file*)malloc(sizeof(t_file*))))
		return (NULL);
	f->fd = -2;
	f = create_file(fd, f);
	return (f);
}

static t_file	*get_file(int fd, t_file *f)
{
	t_file	*tmp;

	if (f->fd == -2)
		return (create_file(fd, f));
	while (f)
	{
		if (f->fd == fd)
			return (f);
		tmp = f;
		f = f->next;
	}
	f = create_file(fd, f);
	tmp->next = f;
	return(f);
}

int	get_next_line(const int fd, char **line)
{
	static t_file	*f;
	t_file		*tf;
//	char		*ts;
//	int		r;

	if (!f)
	{
		if (!(f = (t_file*)malloc(sizeof(t_file*))))
			return (-1);
		f->fd = -2;
		f->line = NULL;
		f->next = NULL;
	}
	if (fd < 0 || !line || read(fd, *line, 0) < 0 || BUFF_SIZE < 0 ||
	!(tf = get_file(fd, f)))
		return (-1);
	if (!ft_strlen(tf->line))
	{
		//free(tf->line);
		free(tf);
		return (0);
	}
	if (!(*line = ft_strdup(ft_strsep(&tf->line, "\n\0"))))
		return (-1);
	return (1);
}
