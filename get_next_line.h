/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:14:57 by pthan             #+#    #+#             */
/*   Updated: 2018/12/27 17:15:00 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 50

typedef struct			s_file
{
	char				*line;
	int					fd;
	struct s_file		*next;
}						t_file;

int						get_next_line(const int fd, char **line);

#endif
