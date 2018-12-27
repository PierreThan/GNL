/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:14:47 by pthan             #+#    #+#             */
/*   Updated: 2018/12/27 17:42:54 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static t_file	*create_file(int fd, t_file *f, int n)
{
	char	buff[BUFF_SIZE + 1];
	int		r;
	char	*tmp;

	if (!f)
	{
		if (!(f = (t_file*)malloc(sizeof(t_file*))))
			return (NULL);
		f->fd = -2;
		f->next = NULL;
	}
	f->fd = fd;
	f->line = ft_strnew(2);
	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		buff[r] = '\0';
		tmp = f->line;
		if (!(f->line = ft_strjoin(f->line, buff)))
			return (NULL);
		if (n++)
			free(tmp);
	}
	f->next = NULL;
	return (f);
}

static t_file	*get_file(int fd, t_file *f)
{
	t_file	*tmp;

	if (f->fd == -2)
		return (create_file(fd, f, 0));
	while (f)
	{
		if (f->fd == fd)
			return (f);
		tmp = f;
		f = f->next;
	}
	f = create_file(fd, f, 0);
	tmp->next = f;
	return (f);
}

/*
   static void	del_file(t_file **begin, t_file *f)
   {
   t_file	*tmp;

   tmp = *begin;
   if (*begin == f)
   {
   if ((*begin)->next)
 *begin = (*begin)->next;
 free(tmp);
 return ;
 }
 while (tmp->next)
 {
 if (tmp->next == f)
 {
 tmp->next = f->next;
 free(f);
 return ;
 }
 tmp = tmp->next;
 }
 }
 */

int				get_next_line(const int fd, char **line)
{
	static t_file	*f;
	t_file			*tf;

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
		return (0);
	if (!(*line = ft_strdup(ft_strsep(&tf->line, "\n\0"))))
		return (-1);
	return (1);
}
