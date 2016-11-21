/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:55:11 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 07:19:51 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	char			*tmp;

	i = ft_strlen(s1);
	tmp = s1 + i;
	*tmp++ = *s2++;
	while (tmp && *s2 && n--)
		*tmp++ = *s2++;
	if (tmp)
		ft_strclr(tmp);
	else
		*(--tmp) = '\0';
	return (s1);
}
