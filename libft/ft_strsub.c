/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:50:54 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/13 17:41:09 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (ptr == NULL || !s)
		return (NULL);
	while (i < len)
	{
		*(ptr + i) = *(s + (start + i));
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
