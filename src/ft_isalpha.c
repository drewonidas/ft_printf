/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 06:45:39 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/23 06:53:23 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (c >= 0)
	{
		if (c >= (int)'a' && c <= (int)'z')
			return (1);
		if (c >= (int)'A' && c <= (int)'Z')
			return (1);
	}
	return (0);
}