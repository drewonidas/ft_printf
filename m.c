#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_printf("%-18s:%+-7irazor\n", av[1], 2000);
		printf("%-18s:%+-7irazor\n", av[1], 2000);
		ft_putstr("\n===========\n\n");
		ft_printf("%-18s:%+7irazor\n", av[1], 2000);
		printf("%-18s:%+7irazor\n", av[1], 2000);
	}
	return (0);
}
