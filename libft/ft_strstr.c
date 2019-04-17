/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:53:56 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/10 15:01:17 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	o;

	i = 0;
	if (*s1 == '\0' && *s2 == '\0')
		return ((char *)s1);
	while (*(s1 + i) != '\0')
	{
		o = 0;
		while (*(s2 + o) != '\0' && *(s1 + (i + o)) == *(s2 + o))
			o++;
		if (*(s2 + o) == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
