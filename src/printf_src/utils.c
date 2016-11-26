#include "ft_printf.h"

int			get_digit(char *format, int *index)
{	
	int		c;
	int		result;
	char	*tmp;

	tmp = ft_strnew(9);
	
		ft_putchar(format[0]);
	format++;
	c = 0;
	result = -1;
	if (format != NULL)
	{
		ft_putendl("bash");
		while (ft_isdigit(*format) && *format)
			tmp[c++] = *format++;
		tmp[c] = '\0';
		result = atoi(tmp);
		ft_strdel(&tmp);
		*index += c;
	}
	return (result);
}
/*
int			get_options(t_flag *flags, t_field *field, char *format, )
{
	int		index;

	index = 0;
	while (ft_strchr((const char *)specs, format[index]) == NULL && format[index])
	{
		if (ft_strchr((const char *)flag_str, format[index]) != NULL)
		{
			flags[ft_indexof(flag_str, format[index])].value = 1;
			index++;
		}
		else if (ft_strchr((const char *)len_mods, format[index]) != NULL)
		{
			if (ft_strncmp(&format[index], "hh", 2) == 0 || ft_strncmp(&format[index], "ll", 2) == 0)
			{
				
				index++;
			}
			index++;
		}
		else if (format[index] == '.')
			field->precision = get_digit(*format[index], &index);
		else if (ft_isdigit(format[index]))
			field->width = get_digit(*format[index], &index);
		//	printf("%c - woosh!!\n", format[index]);
		else
			break;
	}
	return (index);
}*/
