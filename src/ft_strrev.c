#include "libft.h"

void		ft_strrev(char *str)
{
	int		start;
	int		end;
	char	tmp;

	tmp = *str;
	if (tmp == '-')
		start = 1;
	else
		start = 0;
	end = ft_strlen(str) - 1;
	while (start <= end)
	{
		tmp = str[start];
		str[start++] = str[end];
		str[end--] = tmp;
	}
}
