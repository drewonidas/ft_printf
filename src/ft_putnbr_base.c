#include "libft.h"

void				ft_putnbr_base(int nbr, int base)
{
	const char		*range;
	unsigned int	tmp;

	range = "0123456789ABCDEF";
	if (base == 10)
		ft_putnbr(nbr);
	else if (nbr > 0)
	{
		tmp = (unsigned int)nbr;
		ft_putnbr_base(tmp / base, base);
		ft_putchar(range[(nbr % base)]);
	}	
}
