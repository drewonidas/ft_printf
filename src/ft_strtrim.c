/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:57:50 by mdlamini          #+#    #+#             */
/*   Updated: 2016/08/12 14:19:18 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char				*ft_strtrim(char const *s)
{
	char			*new;
	int				i;

	i = 0;
	new = NULL;
	if (s != NULL)
	{
		while ((*s == ' ' || *s == '\t' || *s == '\n') && (*s != '\0'))
			s++;
		i = ft_strlen(s) - 1;
		if (i <= 0)
			return (ft_strdup(""));
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && (i))
			i--;
		new = ft_strnew(++i);
		if (new != NULL)
		{
			new = ft_strncpy(new, s, i);
			return (new);
		}
	}
	return (NULL);
}
