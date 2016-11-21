/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 06:29:18 by mdlamini          #+#    #+#             */
/*   Updated: 2016/08/12 14:21:57 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst != NULL)
	{
		if (content == NULL)
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
		else
		{
			lst->content = ft_strdup(content);
			lst->content_size = content_size;
		}
		lst->next = NULL;
		return (lst);
	}
	return (NULL);
}
