/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:12:35 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/10 18:23:44 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (*(s + i) != '\0')
	{
		*(s + i) = '\0';
		i++;
	}
}
