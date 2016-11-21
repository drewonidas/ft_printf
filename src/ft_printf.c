/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 20:56:38 by mdlamini          #+#    #+#             */
/*   Updated: 2016/06/19 17:57:28 by mdlamini         ###   ########.fr       */
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
	//t_flags			flg;
	const char		*flag_str = "#+-0";
	unsigned int	c;

	flags = (t_flag *)malloc(sizeof(t_flag) * 4);
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

int					print_word(char sp, va_list *args, t_flag *flags, int prec, int width)
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
		print[c](converter, args, prec, width);
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
	int				prec = 0;
	int				width = 0;
	t_flag			*flags;
	const char		*flag_str = "#+-0";
	const char		*specs = "cspxudio";
	const char		*len_mods = "hljz";
	char			*tmpi = NULL;
//	t_constant		*consts;

	va_start(args, format);
//	consts = init_constants();
	flags = init_flags();
	index = 0;
	cnt = 0;
	tmp = -1;
	while (format[index])
	{
		if (format[index] == '%')
		{
			tmp = index++;
			while (ft_strchr((const char *)specs, format[index]) == NULL && format[index])
			{
				if (ft_strchr((const char *)flag_str, format[index]) != NULL)
				{
					flags[ft_indexof(flag_str, format[index])].value = 1;
					index++;
					//continue;
				}
				else if (ft_strchr((const char *)len_mods, format[index]) != NULL)
				{
					if (ft_strncmp(&format[index], "hh", 2) == 0 || ft_strncmp(&format[index], "ll", 2) == 0)
					{
						
						index++;
					}
					index++;
					//continue;
				}
				else if (format[index] == '.')
				{
					int b = 0;
					tmpi = ft_strnew(9);
					index++;
					while (ft_isdigit(format[index]))
						tmpi[b++] = format[index++];
					tmpi[b] = '\0';
					prec = atoi(tmpi);
					ft_strdel(&tmpi);
					//continue;
				}
				else if (ft_isdigit(format[index]) || format[index] == '-')
				{
					int b = 0;
					tmpi = ft_strnew(9);
					printf("%c\n", format[index]);
					while (ft_isdigit(format[index]))
						tmpi[b++] = format[index++];
					tmpi[b] = '\0';
					width = atoi(tmpi);
					ft_strdel(&tmpi);
				}
				else
					break;
			}
					//printf("---%c---\n", format[index]);
			if (print_word(format[index++], &args, flags, prec, width))
			{
				cnt++;
				//ft_putendl("another");
				continue;
			}
			index = tmp;
		}
		ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	free((void *) flags);
//	free(consts);
	return (cnt);
}
