#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

t_gnl		*add_file(int fd, t_gnl *lst)
{
	t_gnl	*res;

	res = NULL;
	if (!lst)
	{
		if (!(lst = (t_gnl*)malloc(sizeof(*lst)) &&
		(lst->line = ft_strnew(BUFF_SIZE))))
			return (NULL);
		lst->fd = fd;
		return (lst)
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

t_gnl		*get_file(int fd, t_gnl *lst)
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

static int	get_line(t_gnl *lst, char **line)
{
	char	*buff;
	int	r;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	r = 0;
	if(lst)
		r = ft_strlen(lst->line);
	while (!ft_strchr(lst->line, '\n') && (r = read(lst->fd, buff, BUFF_SIZE)))
	{
		if (!(lst->line = ft_strjoin(lst->line, buff)))
			return (-1);
	}
	if (r >= 0)
		*line = ft_strjoin(ft_strsep(&lst->line, "\n"), "\n");
//	if (r == 0 && lst && lst->line)
//	{
//		free(lst->line);
//		free(lst);
//	}
	free(buff);
	return (r);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl		*tmp;
	int		r;

	if (fd < 0 || !line)
		return (-1);
	r = -1;
	if (!lst)
	{
		lst = add_file(fd, lst);
		r = get_line(lst, line);
		if (r == 0)
		{	
			free(lst->line);
			free(lst)
		}
	}
	else
	{
		tmp = get_file(fd, lst);
		r = get_line(tmp, line);
		if (r == 0)
		{
			free(tmp->line);
			free(tmp);
		}
	}
	return (r);
}
		//if (!(lst = (t_gnl*)malloc(sizeof(*lst))))
		//	return (-1);
		//lst->line = ft_strnew(BUFF_SIZE);
		//lst->fd = fd;

int	main()
{
	char	**line;
	int 	fd;
	int	r;

	r = -1;
	line = (char**)malloc(sizeof(char*));
	*line = (char*)malloc(sizeof(char)*100);
	fd = open("get_next_line.h", O_RDONLY);
	while ((r = get_next_line(fd, line)) > 0)
	{
		printf("%s", *line);
		//if(line && *line)
		//	free(*line);
		*line = (char*)malloc(sizeof(char)*100);
	}
	if (r == -1)
		printf("\nERREURERREUR\n");
	//free(*line);
	//free(line);
	return (0);
}
/*si le fichier fd est deja commencer, on retrouve sa structure,
sinon on la crée.
si on la crée : lecture du fichier jusqu'a la premiere ligne trouvée.
on remplie le buffer, renvoie la ligne.
si deja créée, on verifie qu'il n'y a pas deja une ligne entiere dans le buffer de la structure, sinon on lit BUFF_SIZE chars et on cherche.*/

