/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:32:10 by aanghel           #+#    #+#             */
/*   Updated: 2022/02/07 23:41:11 by aanghel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return (i);
}

int	ft_format(va_list var, const char str)
{
	int	count;

	count = 0;
	if (str == 's')
		count += ft_write(va_arg(var, char *));
	else if (str == 'c')
		count += ft_char(va_arg(var, int));
	else if (str == 'p')
		count += ft_putesa(va_arg(var, uintptr_t));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(var, int));
	else if (str == 'u')
		count += ft_u(va_arg(var, unsigned int));
	else if (str == 'x' || str == 'X')
		count += ft_esa(va_arg(var, unsigned int), str);
	else if (str == '%')
		count += write(1, "%%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	var;

	i = 0;
	count = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_format(var, str[i + 1]);
			i++;
		}
		else
			count += ft_char(str[i]);
		i++;
	}
	va_end(var);
	return (count);
}
