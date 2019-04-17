/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:43:29 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/13 17:48:36 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t			i;
	char			*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(ptr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*(s + i))
	{
		*(ptr + i) = f(*(s + i));
		i++;
	}
	return (ptr);
}
