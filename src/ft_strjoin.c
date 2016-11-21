/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 05:57:31 by mdlamini          #+#    #+#             */
/*   Updated: 2016/08/11 16:47:53 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	char		*tmp;
	size_t		len_s1;
	size_t		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = ft_strnew(len_s1 + len_s2);
	tmp = NULL;
	if (new != NULL)
	{
		new = ft_strncpy(new, s1, len_s1);
		tmp = new + len_s1;
		tmp = ft_strcpy(tmp, s2);
		return (new);
	}
	return (NULL);
}
