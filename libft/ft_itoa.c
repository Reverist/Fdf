/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:04:37 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/13 14:39:21 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(ptr, "-2147483648"));
	if (n < 0)
	{
		0[ptr] = '-';
		1[ptr] = '\0';
		ptr = ft_strjoin(ptr, ft_itoa(-n));
	}
	else if (n >= 10)
		ptr = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		0[ptr] = n + '0';
		1[ptr] = '\0';
	}
	return (ptr);
}
