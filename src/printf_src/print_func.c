/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:12:07 by mdlamini          #+#    #+#             */
/*   Updated: 2016/06/09 12:13:58 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	process_char(t_converter *converter, va_list arg, int precision, int width)
{
	//while (converter->flags->width--)
	//	ft_putchar(' ');
	converter->data->c = (char) va_arg(arg, int);
	ft_putchar(converter->data->c);
	width++;
	precision++;
}*/

void	process_str(t_converter *converter, va_list *arg, t_field *field)
{
	int	c;
	char *tmp;

	converter->data->str = va_arg(*arg, char *);
	tmp = ft_strdup(converter->data->str);
	c = 0;
	if (converter->flags[2].value != 1)
		pad('s', 'L', converter->flags, field, ft_strlen(tmp));
	if (field->precision > 0)
	{
		while (c < field->precision && tmp[c])
			ft_putchar(tmp[c++]);
	}
	else
		ft_putstr(tmp);
	if (converter->flags[2].value == 1)
		pad('s', 'R', converter->flags, field, ft_strlen(tmp));
	ft_strdel(&tmp);
}

void		process_int(t_converter *converter, va_list *arg, t_field *field)
{
	char	*n;
	unsigned int		len;

//#+-0' '
	converter->data->nbr = va_arg(*arg, int);
	n = ft_itoa(converter->data->nbr);
	len = ft_strlen(n);
	ft_strdel(&n);
	if (converter->flags[2].value != 1 )//|| converter->flags[3].value == 1)
		pad('i', 'L', converter->flags, field, len);
	if (converter->flags[1].value == 1 && converter->data->nbr > 0)
		ft_putchar('+');
	else if (converter->flags[4].value == 1 && converter->data->nbr > 0)
		ft_putchar(' ');
	ft_putnbr(converter->data->nbr);
	if (converter->flags[2].value == 1 )//|| converter->flags[3].value == 1)
		pad('i', 'R', converter->flags, field, len);
}

/*void	process_poi(t_converter *converter, va_list arg, int precision, int width)
{
	converter->data->nbr = va_arg(arg, int);
	ft_putnbr_base(converter->data->nbr, 16);
	width++;
	precision++;
}

void	process_hex(t_converter *converter, va_list arg, int precision, int width)
{
	converter->data->nbr = va_arg(arg, int);
	ft_putnbr_base(converter->data->nbr, 16);
	width++;
	precision++;
}*/
