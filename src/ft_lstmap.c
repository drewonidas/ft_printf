/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 06:32:53 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/30 07:42:39 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;

	new = ft_lstnew(lst->content, lst->content_size);
	if (new == NULL)
		return (NULL);
	lst = lst->next;
	new = new->next;
	while (lst != NULL)
	{
		new = f(lst);
		lst = lst->next;
		new = new->next;
	}
	return (new);
}
