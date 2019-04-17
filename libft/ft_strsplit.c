/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:13:44 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/15 17:02:39 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wrd(char const *s, char c, unsigned int i)
{
	unsigned int len;

	len = 0;
	while (i[s] && i[s] != c)
	{
		++len;
		++i;
	}
	return (len);
}

static int	nbwrd(char const *s, char c)
{
	unsigned int wrd;

	wrd = 0;
	while (*s)
	{
		if (*s == c)
			++s;
		else
		{
			++wrd;
			while (*s && *s != c)
				++s;
		}
	}
	return (wrd);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**ptr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(ptr = (char **)malloc(sizeof(char *) *
		(nbwrd(s, c) + 1))))
		return (NULL);
	while (i[s])
	{
		if (i[s] != c)
		{
			if (!(ptr[j++] = (ft_strsub(s, i, wrd(s, c, i)))))
				return (NULL);
			i += wrd(s, c, i);
		}
		else
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}
