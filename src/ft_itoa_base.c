/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:05:12 by exam              #+#    #+#             */
/*   Updated: 2016/07/30 06:36:26 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int nbr, int base)
{
	char		*tmp;
	const char	*range;
	int			index;

	index = 0;
	range = "0123456789ABCDEF";
	if (base == 10)
		return (ft_itoa(nbr));
	tmp = ft_strnew(sizeof(char) * 10);
	nbr = ABS(nbr);
	while (nbr > 0)
	{
		tmp[index++] = range[(nbr % base)];
		nbr = nbr / base;
	}
	tmp[index] = '\0';
	ft_strrev(tmp);
	return (tmp);
}
