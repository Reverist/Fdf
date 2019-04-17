/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:08:31 by akrivosh          #+#    #+#             */
/*   Updated: 2018/11/17 12:48:48 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int number, int power)
{
	int	res;

	res = number;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		res *= number;
		power--;
	}
	return (res);
}
