#include "libft.h"

/*
 *	adds padding
 *	params:
 *		[char sp - specifier],
 *		[t_flag flags - structure with flag info]
 *		[unsigned int ouput_len - length of output]
 */
	
//#+-0' '
static void		pad_int_left(int padding, t_flag *flags)
{
	while (padding > 0)
	{
		if (flags[1].value > 0)
		{
			ft_putchar('+');
			converter->flags[1].value = 0;
			padding--;
			continue;
		}
		else if (flags[4].value > 1)
		{
			ft_putchar(' ');
			converter->flags[4].value = 0;
			padding--;
			continue;
		}
		padding--;
		if (flags[2].value == 1)
			ft_putchar(' ');
		else
			ft_putchar('0');
		//if (flags[1].value == 1 && padding == 1)
		//	padding--;
	}
}

void			pad(char sp, char side, t_flag *flags, unsigned int output_len)
{
	int			padding;

	padding = width - ABS((int) output_len - precision);
	if (sp == 'i')
	{
		if (side == 'l');
			pad_int_left(padding, flags);
		else
			pad_int_right(padding, flags);
	}
}
