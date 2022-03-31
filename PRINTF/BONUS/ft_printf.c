/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:15:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/03/24 09:33:42 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(char lett, t_flag *flag)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	write(1, &lett, 1);
	count++;
	while (len < (flag->num - count) && flag->less == 1)
		len += ft_putchar(' ');
	return (count + len);
}

int	ft_write(t_flag *f, va_list par)
{
	int	count;

	count = 0;
	if (f->type == 's')
		count += ft_str(va_arg(par, char *), 0, f);
	else if (f->type == 'c')
		count += ft_putc(va_arg(par, int), f);
	else if (f->type == 'd' || f->type == 'i')
		count += ft_putnb(va_arg(par, int), "0123456789", 10, f);
	else if (f->type == 'x')
		count += ft_putnb(va_arg(par, unsigned int), "0123456789abcdef", 16, f);
	else if (f->type == 'X')
		count += ft_putnb(va_arg(par, unsigned int), "0123456789ABCDEF", 16, f);
	else if (f->type == 'p')
		count += ft_putnb_p(va_arg(par, uintptr_t), "0123456789abcdef", 16, f);
	else if (f->type == 'u')
		count += ft_putnb(va_arg(par, unsigned int), "0123456789", 10, f);
	else if (f->type == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_check(const char *str, int i, t_flag *flag)
{
	flag->dot = 0;
	flag->hastag = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->less = 0;
	flag->zero = 0;
	flag->num = 0;
	flag->less_par = 0;
	i++;
	if (str[i] == '.' || str[i] == '-' || str[i] == '+' || str[i] == ' '
		|| (str[i] >= '0' && str[i] <= '9'))
		i += ft_atoi(str, i, flag);
	else if (str[i] == '#')
	{
		flag->hastag = 1;
		i++;
	}
	if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == 'X' || str[i] == '%')
		flag->type = str[i];
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	par;
	t_flag	flag;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(par, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			count += ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
			i = ft_check(str, i, &flag);
			count += ft_write(&flag, par);
			i++;
		}
	}
	return (count);
}
