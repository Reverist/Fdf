/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:57:07 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/10 15:24:13 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	const char		*souce;
	char			*dest;

	souce = src;
	dest = dst;
	i = 0;
	if (dest > souce)
	{
		while (len)
		{
			dest[len - 1] = souce[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			dest[i] = souce[i];
			i++;
		}
	}
	return (dst);
}
