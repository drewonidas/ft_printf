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

typedef struct		s_converter
{
	char			specifier;
	char			*flags;
	char			*data;
	int				precision;
	int				field;
}					t_converter;


void				pad_left(t_converter *conv);

void				pad_right(t_converter *conv);

#endif
