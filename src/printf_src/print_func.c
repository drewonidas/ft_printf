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

void	process_str(t_converter *converter, va_list *arg, int precision, int width)
{
	int	c;
	int padding;
	char *tmp;

	converter->data->str = va_arg(*arg, char *);
	//printf("======%s======\n", converter->data->str);
	tmp = ft_strdup(converter->data->str);
	padding = width - ABS((int)ft_strlen(tmp) -precision);
	c = 0;
	while (padding > 0 && converter->flags[2].value != 1)
	{
		padding--;
		ft_putchar(' ');
	}
	if (precision > 0)
	{
		while (c < precision && tmp[c])
			ft_putchar(tmp[c++]);
	}
	else
		ft_putstr(tmp);
	while (padding > 0 && converter->flags[2].value == 1)
	{
		padding--;
		ft_putchar(' ');
	}
	ft_strdel(&tmp);
}

void	process_int(t_converter *converter, va_list *arg, int precision, int width)
{
//	while (converter->flags->width--)
//	{
//		if (converter->flags->f_0)
//			ft_putchar('0');
//		else
//			ft_putchar(' ');
//	}
	converter->data->nbr = 0;
	int n = va_arg(*arg, int);
	ft_putnbr(n);
	width++;
	precision++;
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
