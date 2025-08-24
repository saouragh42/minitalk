/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:02:55 by saouragh          #+#    #+#             */
/*   Updated: 2024/12/19 20:34:15 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_intlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int num)
{
	char	*str;
	int		size;

	size = ft_unsigned_intlen(num);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[--size] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

int	ft_print_unsigned_int(unsigned int num)
{
	int		count;
	char	*str;

	count = 0;
	if (num == 0)
		return (ft_print_char('0'));
	str = ft_utoa(num);
	if (!str)
		return (-1);
	count += ft_print_string(str);
	free(str);
	return (count);
}
