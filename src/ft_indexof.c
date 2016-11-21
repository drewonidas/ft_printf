#include "libft.h"

int			ft_indexof(const char *str, char c)
{
	int		cnt;

	cnt = 0;
	while (str[cnt])
	{
		if (str[cnt] == c)
			return (cnt);
		cnt++;
	}
	return (-1);
}
