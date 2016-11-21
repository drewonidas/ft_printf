/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 05:54:35 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 05:54:40 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (new != NULL)
	{
		new = ft_memset(new, 0, size);
		return (new);
	}
	return (NULL);
}
