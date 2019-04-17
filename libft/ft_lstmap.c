/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:46:38 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/17 13:35:47 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*created;
	t_list	*tempo;

	if (!lst || !f)
		return (NULL);
	tempo = f(lst);
	if ((newlst = ft_lstnew(tempo->content, tempo->content_size)))
	{
		created = newlst;
		lst = lst->next;
		while (lst != NULL)
		{
			tempo = (*f)(lst);
			if (!(created->next = ft_lstnew(tempo->content,
				tempo->content_size)))
				return (NULL);
			created = created->next;
			lst = lst->next;
		}
	}
	return (newlst);
}
