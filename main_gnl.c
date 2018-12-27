#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"


int	main(int argc, char **argv)
{
	/*
	char	**line;
	char	**line2;
	int 	fd;
	int 	fd2;
	int	r;
	int	i;
	int	j;

	line = (char**)malloc(sizeof(char*));
	line2 = (char**)malloc(sizeof(char*));
	fd = open("get_next_line.h", O_RDONLY);
	fd2 = open("main.c", O_RDONLY);
//	printf("\n	numero du fd : %i\n", fd);
//	if (r == -1)
//		printf("\n\nERREURERREUR\n\n");
	i = 1;
	j = 1;
//	close(fd);
//	printf("\n	numero du fd : %i\n", fd);
	while (i < 5 && (r = get_next_line(fd, line)) > 0)
	{
		printf("%i : %s\n",i, *line);
		i++;
	}
	while (j < 5 && (r = get_next_line(fd2, line2)))
	{
		printf("%i : %s\n", j, *line2);
		j++;
	}
	while ((r = get_next_line(fd, line)) > 0)
	{
		printf("%i : %s\n",i, *line);
		i++;
	}
	while ((r = get_next_line(fd2, line2)))
	{
		printf("%i : %s\n", j, *line2);
		j++;
	}
	close(fd);
	close(fd2);
	if (r == -1)
		printf("\n\nERREURERREUR\n\n");
	free(line);
	return (0);
	*/

	char *line = NULL;
	int i = 0;
	
	int fd = open (argv[1], 2);
	if(fd < 0)
	{
		printf("Error opening file [%s]\n", argv[1]);
		return 0;
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("[%d][%s]\n", i, line);
		if (line)
			free(line);
		line = NULL;
	}
	printf("[BEFOR EXIT] [%d]\n", i);
	while (1);
}
