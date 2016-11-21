/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 05:56:48 by mdlamini          #+#    #+#             */
/*   Updated: 2016/08/11 16:47:00 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*tmp;

	new = ft_strnew(ft_strlen(s));
	if (new != NULL)
	{
		tmp = new;
		while (*s)
			*tmp++ = f(*s++);
		*tmp = '\0';
		return (new);
	}
	else
		return (NULL);
}
