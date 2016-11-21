/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 06:26:18 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 07:41:33 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nbr, int fd)
{
	if (nbr < 0)
		ft_putchar_fd('-', fd);
	nbr = ABS(nbr);
	if (nbr <= 9)
		ft_putchar_fd(nbr + '0', fd);
	else if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
}
