/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 20:28:50 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 07:45:45 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = ft_strlen((const char *)dst);
	while (&dst[i] && *src && size--)
		dst[i++] = *src++;
	if (&dst[i])
		dst[i] = '\0';
	return ((size_t)i);
}
