/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:24:10 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/10 14:40:58 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int j;

	j = 0;
	while ((s1[j] == s2[j]) && s1[j] && s2[j])
		j++;
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
