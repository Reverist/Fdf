/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:15:21 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/06 15:55:11 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	i;
	const char		*souce;
	char			*dest;

	souce = src;
	dest = dst;
	i = 0;
	while (i < n)
	{
		dest[i] = souce[i];
		i++;
	}
	return (dst);
}
