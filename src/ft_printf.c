/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 20:56:38 by mdlamini          #+#    #+#             */
/*   Updated: 2016/11/26 16:21:12 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int					get_digit(char *format, int *index)
{	
	int				result;
	char			*tmp;
	int				c;

	tmp = ft_strnew(9);
	c = 0;
	if (format[*index] == '.')
		(*index)++;
	while (ft_isdigit(format[*index]) && format[*index])
	{
		tmp[c++] = format[*index];
		(*index)++;
	}
	tmp[c] = '\0';
	result = atoi(tmp);
	ft_strdel(&tmp);
	(*index)--;
	return (result);
}

char				*get_arg_as_str(char sp, char *flags, va_list *arg)
{
	char			*result;

	result = NULL;
	if (sp == 'c') {
		result = ft_strnew(2);
		result[0] = (char) va_arg(*arg, int);
	}
	else if (sp == 's')
		return (ft_strdup(va_arg(*arg, char *)));
	else if (ft_strchr("diu", sp))
		return (ft_itoa(va_arg(*arg, int)));
	else if (ft_strchr("xXp", sp))
	{
		result = ft_itoa_base(va_arg(*arg, int), 16);
		if (ft_strchr(flags, '#') || sp == 'p')
			return (ft_strjoin("0x", result));
	}
	else if (ft_strchr("oO", sp))
	{
		result = ft_itoa_base(va_arg(*arg, int), 8);
		if (ft_strchr(flags, '#') && result[0] != '0')
			return (ft_strjoin("0", result));
	}
	return (result);
}

int					print(t_converter *conv)
{
	int				c;
	int				result;

	c = 0;
	result = 0;
	if (conv->specifier == '%')
	{
		ft_putchar('%');
		result = 1;
	}
	else
	{
		pad_left(conv);
		if (conv->precision > 0)
		{
			while (c < conv->precision && conv->data[c])
				ft_putchar(conv->data[c++]);
		}
		else
			ft_putstr(conv->data);
		pad_right(conv);
		result = (c > conv->field) ? c : conv->field;
	}
	return (result);
}

void				get_converter(const char *tmp_str, int *t_index, t_converter *conv)
{
	const char		*flag_str = "#+-0 ";
	const char		*specs = "cspxudio";
	int				f_index;

	f_index = 0;
	conv->flags = ft_strnew(6);
	conv->specifier = 0;
	conv->data = NULL;
	conv->precision = 0;
	conv->field = 0;
	while (ft_strchr((const char *)specs, tmp_str[*t_index]) == NULL && tmp_str[*t_index])
	{
		if (ft_strchr((const char *)flag_str, tmp_str[*t_index]) != NULL)
			conv->flags[f_index++] = tmp_str[*t_index];
		else if (tmp_str[*t_index] == '.')
			conv->precision = get_digit((char *)tmp_str, t_index);
		else if (ft_isdigit(tmp_str[*t_index]))
			conv->field = get_digit((char *)tmp_str, t_index);
		else
			break;
		(*t_index)++;
	}
	conv->specifier = tmp_str[*t_index];
}

int					ft_printf(const char *format, ...)
{
	va_list			args;
	int				index;
	int				cnt;
	t_converter		conv;

	va_start(args, format);
	index = 0;
	cnt = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			get_converter(format, &index, &conv);
			conv.data = get_arg_as_str(conv.specifier, conv.flags, &args);
			if ((cnt += print(&conv)) > 0)
			{
				index++;
				ft_strdel(&(conv.flags));
				ft_strdel(&(conv.data));
				continue;
			}
		}
		ft_putchar(format[index++]);
		cnt++;
	}
	va_end(args);
	return (cnt);
}
