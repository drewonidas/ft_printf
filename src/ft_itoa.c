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

static int	str_size(int nbr)
{
	int		cnt;

	cnt = 0;
	if (nbr < 0)
		cnt++;
	nbr = ABS(nbr);
	if (nbr < 10)
		cnt++;
	else
	{
		while (nbr >= 1)
		{
			nbr = nbr / 10;
			cnt++;
		}
	}
	return (cnt);
}

char		*ft_itoa(int nbr)
{
	char	*tmp;
	int		index;

	index = 0;
	tmp = ft_strnew(str_size((size_t)nbr));
	if (nbr < 0)
		tmp[index++] = '-';
	nbr = ABS(nbr);
	if (nbr < 10)
		tmp[index++] = nbr + '0';
	else
	{
		while (nbr > 0)
		{
			tmp[index++] = (nbr % 10) + '0';
			nbr = nbr / 10;
		}
	}
	tmp[index] = '\0';
	ft_strrev(tmp);
	return (tmp);
}
