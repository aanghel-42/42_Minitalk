/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:26:07 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/09 02:40:51 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bp(unsigned long int nbr, char *b, unsigned long int l_b, int count)
{
	if (nbr >= l_b)
	{
		ft_bp(nbr / l_b, b, l_b, count);
		ft_putchar(b[nbr % l_b]);
	}
	else if (nbr >= 0)
		ft_putchar(b[nbr % l_b]);
}

int	ft_putnb_p(unsigned long int nbr, char *base, int l_base, t_flag *flag)
{
	int					count;
	unsigned long int	n;

	count = 0;
	n = nbr;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = n / l_base;
		count++;
	}
	count = ft_check_before (flag, count);
	ft_bp(nbr, base, l_base, count);
	count += ft_check_after(flag, count);
	return (count);
}
