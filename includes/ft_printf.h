#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

union				u_data
{
	int				nbr;
	//size_t			st_nbr;
	//long int		lg_nbr;
	//short int		sh_nbr;
	//intmax_t		mx_nbr;
	//unsigned int	un_nbr;
	//long long int	ll_nbr;
	char			c;
	//wint_t			wt_c;
	//unsigned char	un_c;
	char			*str;
	//wchar_t			*wc_str;
};

/*typedef	enum		e_specifiers
{
	s,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	c,
	C
}					t_specifier;

typedef enum		e_flags
{
	hash = '#',
	plus = '+',
	minus = '-',
	zero = '0'
}					t_flags;

typedef enum		e_mods
{
	hh,
	h,
	l,
	ll,
	j,
	z
}					t_mods;
*/
typedef struct		s_flag
{
	char			flag;
	int				value;
}					t_flag;

typedef struct		s_converter
{
	t_flag			*flags;
	union u_data	*data;
}					t_converter;

typedef struct		s_field
{
	int				precision;
	int				width;
}					t_field;

typedef 			void (*t_print)(t_converter *, va_list*, t_field *);

void				process_char(t_converter *converter, va_list arg, int precision, int width);

void				process_str(t_converter *converter, va_list *arg, t_field *field);

void				process_int(t_converter *converter, va_list *arg, t_field *field);

void				process_poi(t_converter *converter, va_list arg, int precision, int width);

void				process_hex(t_converter *converter, va_list arg, int precision, int width);

void				process_oct(t_converter *converter, va_list arg, int precision, int width);

void				process_dec(t_converter *converter, va_list arg, int precision, int width);

void				pad(char sp, char side, t_flag *flags, t_field *attr, unsigned int output_len);

int					get_digit(char *format, int *index);

#endif
