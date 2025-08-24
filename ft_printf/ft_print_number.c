/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:01:35 by saouragh          #+#    #+#             */
/*   Updated: 2024/12/19 20:02:02 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_symbols(int is_up)
{
	if (is_up)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

int	ft_print_number_base(long num, int base, int is_up)
{
	int		count;
	int		r;

	if (num == 0)
		return (ft_print_char('0'));
	if (num == -2147483648)
		return (ft_print_string("-2147483648"));
	count = 0;
	if (num < 0 && (count++ || 1) && ft_print_char('-') == -1)
		return (-1);
	if (num < 0)
		num = -num;
	if (num >= base)
	{
		r = ft_print_number_base(num / base, base, is_up);
		if (r == -1)
			return (-1);
		count += r;
	}
	r = ft_print_char(ft_symbols(is_up)[num % base]);
	if (r == -1)
		return (-1);
	return (count + r);
}

int	ft_print_number_hex(unsigned int nbr, int base, int is_up)
{
	return (ft_print_number_base(nbr, base, is_up));
}
