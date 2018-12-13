#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5000

typedef struct	s_file
{
	char			*line;
	int			fd;
	struct s_file		*next;
}		t_file;

int		get_next_line(const int fd, char **line);

#endif
