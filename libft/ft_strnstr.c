/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:02:20 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/13 16:45:40 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t o;

	i = 0;
	while (*(s1 + i) != '\0' && i < n)
	{
		o = 0;
		while (*(s2 + o) != '\0'
				&& *(s1 + (i + o)) == *(s2 + o) && (o + i) < n)
			o++;
		if (*(s2 + o) == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
