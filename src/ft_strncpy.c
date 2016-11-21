/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:51:58 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 07:05:55 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*new;
	size_t	size;

	new = (char *)ft_memcpy((void *)dst, (const void *)src, len);
	size = ft_strlen(src);
	if (len <= size)
		ft_strclr(&new[len]);
	return (new);
}
