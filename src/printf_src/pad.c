#include "ft_printf.h"

/*
 *	adds padding
 *	params:
 *		[char sp - specifier],
 *		[t_flag flags - structure with flag info]
 *		[unsigned int ouput_len - length of output]
 */
	
static void		pad(t_converter *conv, char pad_chr)
{
	int			padding;
	int			out_len;

	out_len = ft_strlen(conv->data);
	padding = ABS(conv->field - ((int) out_len - conv->precision));
	while (padding-- > 0)
		ft_putchar(pad_chr);
}

void			pad_right(t_converter *conv)
{
	if (ft_strchr(conv->flags, '-'))
	{
		pad(conv, ' ');
	}
}

void			pad_left(t_converter *conv)
{
	char		tmp;

	tmp = 0;
	if (ft_strchr("di", conv->specifier))
	{
		if (ft_strchr(conv->flags, '+'))
			tmp = '+';
		else if (ft_strchr(conv->flags, ' '))
			tmp = ' ';
	}
	if (tmp > 0)
		conv->field--;
	if (ft_strchr(conv->flags, '-') || ft_strchr(conv->flags, '0'))
	{
		ft_putchar(tmp);
		tmp = 0;
	}
	if (ft_strchr(conv->flags, '-') == NULL)
	{
		if (ft_strchr(conv->flags, '0') && ft_strchr("dioux", conv->specifier))
			pad(conv, '0');
		else
			pad(conv, ' ');
		ft_putchar(tmp);
	}
}
