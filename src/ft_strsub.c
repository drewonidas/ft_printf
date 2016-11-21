/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 05:57:23 by mdlamini          #+#    #+#             */
/*   Updated: 2016/08/11 16:46:49 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		i;

	i = 0;
	new = ft_strnew(len);
	if (new != NULL)
	{
		while (s[start] && i < len && new[i] == '\0')
			new[i++] = s[start++];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
