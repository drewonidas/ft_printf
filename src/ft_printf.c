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

/*t_constant			*init_contants()
{
	t_constant		*constants;

	constants = (t_constant *)malloc(sizeof(t_constant));
	constants->specifiers = "cspxudio";
	constants->flags = "#+-0";
	constants->len_mods = "hljz";
	return (constants);
}*/
//TODO: implement using linked lists
t_flag				*init_flags()
{
	t_flag			*flags;
	const char		*flag_str = "#+-0 ";
	unsigned int	c;

	flags = (t_flag *)malloc(sizeof(t_flag) * 6);
	c = 0;
	while (flag_str[c])
	{
		flags[c].flag = flag_str[c];
		flags[c++].value = 0;
	}
	return (flags);
}

t_print				*init_funcs(size_t size)
{
	t_print			*print;

	print = (t_print *)malloc(sizeof(t_print) * size);
//	print[0] = &process_char;
	print[0] = &process_str;
//	print[2] = &process_hex;
//	print[3] = &process_hex;
//	print[4] = &process_hex;
//	print[5] = &process_int;
	print[1] = &process_int;
//	print[7] = &process_oct;
	print[2] = NULL;
	return (print);
}

int					print_word(char sp, va_list *args, t_flag *flags, t_field *field)
{
	t_print			*print;
	t_converter		*converter;
	int				c;
	char			*specs;
	int				result;

	c = 0;
	specs = "si";//"cspxudio";
	print = init_funcs(10);
	converter = (t_converter *)malloc(sizeof(t_converter));
	converter->data = (union u_data *)malloc(sizeof(union u_data));
	converter->flags = flags;
	result = 0;
	if (sp == '%')
	{
		ft_putchar('%');
		result = 1;
	}
	c = ft_indexof(specs, sp);
	if (c != -1)
	{
		print[c](converter, args, field);
		result = 1;
	}
	free((void *) converter->data);
	free((void *) print);
	free((void *) converter);
	return (result);
}
//TODO: fix printf return value
int					ft_printf(const char *format, ...)
{
	va_list			args;
	int				index;
	int				cnt;
	int				tmp;
	t_field			field;
	t_flag			*flags;
	const char		*flag_str = "#+-0 ";
	const char		*specs = "cspxudio";
	const char		*len_mods = "hljz";

	va_start(args, format);
	field.precision = 0;
	field.width = 0;
	flags = NULL;
	index = 0;
	cnt = 0;
	tmp = -1;
	while (format[index])
	{
		if (format[index] == '%')
		{
			tmp = index++;
			flags = init_flags();
			while (ft_strchr((const char *)specs, format[index]) == NULL && format[index])
			{
				if (ft_strchr((const char *)flag_str, format[index]) != NULL)
					flags[ft_indexof(flag_str, format[index++])].value = 1;
				else if (ft_strchr((const char *)len_mods, format[index]) != NULL)
				{
					if (ft_strncmp(&format[index], "hh", 2) == 0 || ft_strncmp(&format[index], "ll", 2) == 0)
					{
						
						index++;
					}
					index++;
				}
				else if (format[index] == '.')
					field.precision = get_digit((char *)format, &index);
				else if (ft_isdigit(format[index]))
					field.width = get_digit((char *)format, &index);
				//	printf("%c - woosh!!\n", format[index]);
				else
					break;
			}
					//printf("---%c---\n", format[index]);
				//ft_putendl("another");
			if (print_word(format[index++], &args, flags, &field))
			{
				cnt++;
				free((void *) flags);
				flags = NULL;
				continue;
			}
			index = tmp;
		}
		ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	if (flags != NULL)
		free((void *) flags);
	return (cnt);
}
