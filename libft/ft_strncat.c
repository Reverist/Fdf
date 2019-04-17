/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:32:10 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/10 15:20:08 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char		*dest;
	const char	*souce;

	dest = s1;
	souce = s2;
	while (*dest)
		dest++;
	while (*souce && n--)
	{
		*dest = *souce;
		dest++;
		souce++;
	}
	*dest = '\0';
	return (s1);
}
