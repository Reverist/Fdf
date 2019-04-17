/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:07:09 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/10 15:24:51 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char		*dest;
	const char	*souce;

	dest = s1;
	souce = s2;
	while (*dest)
		dest++;
	while (*souce)
	{
		*dest = *souce;
		dest++;
		souce++;
	}
	*dest = '\0';
	return (s1);
}
