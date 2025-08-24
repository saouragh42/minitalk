/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:03:54 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/08 13:58:21 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_print_char(int c);

size_t	ft_strlen_printf(const char *str);

int		ft_print_string(char *str);

void	ft_print_ptr(uintptr_t ptr);

size_t	ft_ptrlen(uintptr_t ptr);

int		ft_print_pointer(unsigned long long ptr);

int		ft_print_number_hex(unsigned int nbr, int base, int is_up);

int		ft_print_number_base(long num, int base, int is_up);

int		ft_unsigned_intlen(unsigned int n);

char	*ft_utoa(unsigned int num);

int		ft_print_unsigned_int(unsigned int num);

int		ft_print_format(const char specifier, va_list args);

int		ft_printf(const char *str, ...);

#endif
