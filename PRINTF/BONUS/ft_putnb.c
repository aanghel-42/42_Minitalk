/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:34:42 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/09 02:19:15 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_before_continue(t_flag *f, int len, int lim, int count)
{
	if (f->dot == 1 && f->num > 0)
	{
		while (len < (f->num - lim + f->less_par))
			len += ft_putchar('0');
	}
	else if (f->num >= 0 && f->less == 0 && f->hastag == 0)
	{
		if (f->type == 'p')
		{
			while (len < (f->num - lim - 2))
				len += ft_putchar(' ');
		}
		else
		{
			while (len < (f->num - lim))
				len += ft_putchar(' ');
		}
	}
	if (f->type == 'p')
	{
		write (1, "0x", 2);
		count += 2;
	}
	return (count + len);
}

int	ft_check_before(t_flag *f, int count)
{
	int	len;
	int	lim;

	len = 0;
	lim = count;
	if (f->less_par == 0 && f->plus == 1 && f->space == 0)
		count += ft_putchar('+');
	else if (f->space == 1 && f->less_par == 0
		&& (f->type == 'd' || f->type == 'i'))
		count += ft_putchar(' ');
	if (f->less_par == 1 && (f->zero == 1 || f->dot == 1))
		ft_putchar('-');
	if (f->type != 'p' && (f->less == 0 && f->num > 0 && f->zero == 1))
	{
		while (len < (f->num - lim))
			len += ft_putchar('0');
	}
	if (f->hastag == 1 && (f->type == 'x' || f->type == 'X'))
	{
		count += ft_putchar ('0');
		count += ft_putchar (f->type);
	}
	count = ft_check_before_continue(f, len, lim, count);
	return (count);
}

int	ft_check_after(t_flag *flag, int count)
{
	int	len;

	len = 0;
	if (flag->less == 1)
	{
		while (len < (flag->num - count))
			len += ft_putchar(' ');
	}
	return (len);
}

void	ft_putnbr_base(int long long nbr, char *base, int l_base, int count)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nbr, base, l_base, count);
	}
	else if (nbr >= l_base)
	{
		ft_putnbr_base(nbr / l_base, base, l_base, count);
		ft_putchar(base[nbr % l_base]);
	}
	else if (nbr >= 0)
		ft_putchar(base[nbr % l_base]);
}

int	ft_putnb(int long long nbr, char *base, int l_base, t_flag *flag)
{
	int	count;

	count = 0;
	if (nbr < 0)
		flag->less_par = 1;
	if (nbr < 0 && (flag->zero == 1 || flag->dot == 1))
		nbr = nbr * -1;
	if (flag->hastag == 1 && nbr == 0)
		flag->hastag = 0;
	count += ft_l(nbr, l_base, flag) + flag->less_par;
	count = ft_check_before (flag, count);
	ft_putnbr_base(nbr, base, l_base, count);
	count += ft_check_after(flag, count);
	return (count);
}
