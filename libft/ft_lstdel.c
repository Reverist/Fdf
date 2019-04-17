/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:08:05 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/16 18:25:50 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *a;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		a = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free((*alst));
		*alst = a;
	}
	*alst = NULL;
}
