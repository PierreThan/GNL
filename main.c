#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"


int	main()
{
	char	**line;
	int 	fd;
	int 	fd2;
	int	r;
	int	i = 0;

	line = (char**)malloc(sizeof(char*));
	fd = open("get_next_line.h", O_RDONLY);
//	printf("\n	numero du fd : %i\n", fd);
//	while ((r = get_next_line(fd, line)) > 0 && ++i)
//		printf("%s\n", *line);
//	if (r == -1)
//		printf("\n\nERREURERREUR\n\n");
	i = 0;
//	close(fd);
	fd2 = open("main.c", O_RDONLY);
//	printf("\n	numero du fd : %i\n", fd);
	while ((r = get_next_line(fd, line)) > 0 && ++i)
	{
		printf("%i",i);
		printf("%s\n", *line);
	}
	if (r == -1)
		printf("\n\nERREURERREUR\n\n");
	free(line);
	return (0);
/*azndonaziondiniozanda*/}