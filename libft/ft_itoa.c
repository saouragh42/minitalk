/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:32:32 by saouragh          #+#    #+#             */
/*   Updated: 2024/11/17 22:39:18 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_res(int size, int is_neg, char *res, unsigned int nbr)
{
	res[size--] = '\0';
	while (size >= 0)
	{
		res[size] = nbr % 10 + '0';
		nbr /= 10;
		size--;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	int				is_neg;
	int				size;
	char			*res;
	unsigned int	nbr;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	if (n < 0)
		nbr = (unsigned int)(-n);
	else
		nbr = (unsigned int) n;
	size = ft_intlen(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	return (ft_itoa_res(size, is_neg, res, nbr));
}
