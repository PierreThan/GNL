#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000000

typedef struct	s_list_gnl
{
	char			*line;
	int			fd;
	struct s_list_gnl	*next;
}		t_lst_gnl;

int		get_next_line(const int fd, char **line);

#endif
