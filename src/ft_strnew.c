/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 05:54:50 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 07:36:33 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)ft_memalloc(sizeof(char) * size + 1);
	if (new)
		new = (char *)ft_memset((void *)new, 0, size);
	else
		return (NULL);
	return (new);
}
