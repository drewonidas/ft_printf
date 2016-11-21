/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 05:13:29 by mdlamini          #+#    #+#             */
/*   Updated: 2016/08/11 17:03:32 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				nbr;
	int				neg;
	unsigned int	dec;

	nbr = 0;
	neg = 1;
	dec = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		//nbr *= dec;
		nbr = (nbr * dec) + ((int)(*str - '0'));
		dec *= 10;
		str++;
	}
	return ((nbr * neg));
}
