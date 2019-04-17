/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:15 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/13 16:55:55 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t j;

	j = 0;
	if (!n)
		return (0);
	while ((j[s1] == j[s2] && j[s2] && j < n - 1))
		j++;
	return ((unsigned char)j[s1] - (unsigned char)j[s2]);
}
