/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:19:06 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/10 15:20:45 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t o;

	i = 0;
	o = 0;
	while (*(dst + i) && i < size)
		i++;
	while (*(src + o) && ((i + o + 1) < size))
	{
		*(dst + (o + i)) = *(src + o);
		o++;
	}
	if (i != size)
		dst[o + i] = '\0';
	return (i + ft_strlen(src));
}
