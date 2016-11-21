#include "ft_printf.h"
#include <stdio.h>

typedef void (*func)(const char *);

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_printf("%-18i%s\n", av[1], 2000);
		printf("%-18i:%s\n", av[1], 2000);
	}
	return (0);
}
