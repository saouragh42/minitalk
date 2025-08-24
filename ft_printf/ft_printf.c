/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:03:20 by saouragh          #+#    #+#             */
/*   Updated: 2024/12/19 20:03:29 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(const char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(args, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_number_base(va_arg(args, int), 10, 0);
	else if (specifier == 'u')
		count += ft_print_unsigned_int(((va_arg (args, unsigned int))));
	else if (specifier == 'x')
		count += ft_print_number_hex(va_arg (args, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += ft_print_number_hex(va_arg (args, unsigned int), 16, 1);
	else
		count += write(1, &specifier, 1);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		r;

	if (!str || *str == '\0')
		return (0);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
			r = write(1, str++, 1);
		else if (*str == '%' && *(str + 1) == '\0')
			r = 0;
		else if (*str == '%')
			r = ft_print_format(*(++str), args);
		else
			r = ft_print_char(*str);
		if (r == -1)
			return (-1);
		count += r;
		str++;
	}
	va_end(args);
	return (count);
}
