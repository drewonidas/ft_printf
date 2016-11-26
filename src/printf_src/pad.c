#include "ft_printf.h"

/*
 *	adds padding
 *	params:
 *		[char sp - specifier],
 *		[t_flag flags - structure with flag info]
 *		[unsigned int ouput_len - length of output]
 */
	
static void		pad_str(int padding)
{
	while (padding > 0)
	{
		padding--;
		ft_putchar(' ');
	}
}

static void		pad_int_right(int padding, t_flag *flags)
{
	while (padding > 0)
	{
		padding--;
		if (flags[2].value == 1)
			ft_putchar(' ');
		else
			ft_putchar('0');
	}
}

//#+-0' '
static void		pad_int_left(int padding, t_flag *flags)
{
	int right;

	right = 0;
	while (padding > 0)
	{
		if (flags[1].value > 0 && flags[3].value == 1)
		{
			ft_putchar('+');
			flags[1].value = 0;
			right = 1;
			padding--;
			continue;
		}
		else if (flags[4].value > 1)
		{
			ft_putchar(' ');
			flags[4].value = 0;
			padding--;
			continue;
		}
		padding--;
		if (flags[3].value != 1)
			ft_putchar(' ');
		else
			ft_putchar('0');
		if (right && padding == 1)
			padding--;
	}
}

void			pad(char sp, char side, t_flag *flags, t_field *attr, unsigned int output_len)
{
	int			padding;

	padding = attr->width - ABS((int) output_len - attr->precision);
	if (sp == 'i')
	{
		if (side == 'L')
			pad_int_left(padding, flags);
		else
			pad_int_right(padding, flags);
	}
	else
	{
		pad_str(padding);
	}
	sp = 'a';

}
