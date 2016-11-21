/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:56:02 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 07:04:42 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		tmp_c;
	const unsigned char	*tmp_s;

	tmp_c = (unsigned char)c;
	tmp_s = (const unsigned char *)s;
	while (n--)
	{
		if (*tmp_s == tmp_c)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return (NULL);
}
