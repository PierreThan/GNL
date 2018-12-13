#include "get_next_line.h"
#include "libft/libft.h"

t_file		*add_file(int fd, t_file *f)
{
	t_file	*new;

	new = NULL;
	if (f->fd == -2)
	{
		if (!(f->line = ft_strnew(BUFF_SIZE)) || (read(fd, f->line, BUFF_SIZE == -1)))
			return (NULL);
		f->fd = fd;
		return (f);
	}
	else
	{
		while (f->next)
			f = f->next;
		if (!(new = add_file(fd, f)))
			return (NULL);
		f->next = new;
		return (new);
	}
}

t_file		*get_file(int fd, t_file *f)
{
	if (f->fd == -2)
		return (add_file(fd, f));
	while (f)
	{
		if (f->fd == fd)
			return (f);
		f = f->next;
	}
	return (add_file(fd, f));
}
/*
void		del_file(t_file **begin, t_file *file)
{
	t_file	*tmp1;
	t_file	*tmp2;
	t_file	*tmp;

	tmp = *begin;
	tmp1 = tmp;
	if (*begin == file)
	{
		tmp2 = file->next;
		free(file->line);
	}
}
*/

static int	get_line(t_file *f, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int	r;

	r = 1;
	while (!ft_strchr(f->line, '\n') && r)
	{
		r = read(f->fd, buff, BUFF_SIZE);
		if (r)
		{
			buff[r] = '\0';
			tmp = f->line;
			if (!(f->line = ft_strjoin(f->line, buff)))
				return (-1);
			free(tmp);
		}
	}
	*line = ft_strdup(ft_strsep(&f->line, "\n"));
//	printf("%s11111111\n", f->line);	///////
	if (r == 0 && (*(f->line) == '\0'))
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*f;
	t_file		*tmp;
	int		r;

	if (!f)
	{
		f = (t_file*)malloc(sizeof(t_file*));
		f->fd = -2;
		f->line = NULL;
		f->next = NULL;
	}
	if (fd < 0 || !line || read(fd, *line, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	if ((tmp = get_file(fd, f)) == NULL || (r = get_line(tmp, line)) == -1)
		return (-1);
	if (r == 0 && f && f->line && *(f->line))
		return (1);
	if (r == 0)
		tmp->fd = -2;
	return (r);
}
/*
int	main()
{
	char	**line;
	int 	fd;
	int 	fd2;
	int	r;
	int	i = 0;

	line = (char**)malloc(sizeof(char*));
	fd = open("get_next_line.h", O_RDONLY);
	printf("numero du fd : %i", fd);
	while ((r = get_next_line(fd, line)) > 0 && ++i)
		printf("%s\n", *line);
	if (r == -1)
		printf("\n\nERREURERREUR\n\n");
	i = 0;
	fd2 = open("main.c", O_RDONLY);
	printf("numero du fd2 : %i", fd);
	while ((r = get_next_line(fd2, line)) > 0 && ++i)
		printf("%s\n", *line);
	free(line);
	return (0);
}*/
