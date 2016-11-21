/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:19:14 by mdlamini          #+#    #+#             */
/*   Updated: 2016/06/09 12:16:08 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_oct(t_converter *converter, va_list arg, int precision, int width)
{
	converter->data->nbr = va_arg(arg, int);
	ft_putnbr_base(converter->data->nbr, 8);
	width++;
	precision++;
}

void	process_dec(t_converter *converter, va_list arg, int precision, int width)
{
	converter->data->nbr = va_arg(arg, int);
	ft_putnbr(converter->data->nbr);
	width++;
	precision++;
}
