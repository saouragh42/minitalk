/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:25:58 by saouragh          #+#    #+#             */
/*   Updated: 2024/11/19 20:56:02 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_edge_cases(int is_neg)
{
	if (is_neg)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		is_neg;
	long	res;

	i = 0;
	is_neg = 0;
	res = 0;
	while (str[i] && ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			is_neg = 1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		if (res > (LONG_MAX - (str[i] - '0')) / 10)
			return (ft_atoi_edge_cases(is_neg));
		res = res * 10 + (str[i++] - '0');
	}
	if (is_neg)
		res = res * (-1);
	return ((int) res);
}
