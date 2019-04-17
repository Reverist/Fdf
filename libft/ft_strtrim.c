/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:17:39 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/13 17:54:22 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (ft_invchar(*(s + i)))
		i++;
	if (*(s + i) == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	j = ft_strlen(s) - 1;
	while (ft_invchar(*(s + j)))
		j--;
	if (!(ptr = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (k < j - i + 1)
	{
		*(ptr + k) = *(s + (i + k));
		k++;
	}
	*(ptr + k) = '\0';
	return (ptr);
}
