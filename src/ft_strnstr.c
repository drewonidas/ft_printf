/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 04:53:46 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 07:23:33 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t n)
{
	int			i;
	int			match;
	size_t		cnt;

	i = 0;
	match = 0;
	cnt = n;
	if (!(*little))
		return ((char *)big);
	while (*big != '\0')
	{
		while (big[i] == little[i] && cnt-- && big[i] && little[i])
		{
			match++;
			i++;
		}
		if (match == (int)ft_strlen(little))
			return ((char *)big);
		big++;
		match = 0;
		i = 0;
		cnt = n;
	}
	return (NULL);
}
