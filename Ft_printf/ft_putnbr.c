/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:32:18 by aanghel           #+#    #+#             */
/*   Updated: 2022/02/07 23:46:33 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_digit(long nb)
{
	int	n;

	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_digit(nb / 10);
		n = (nb % 10) + 48;
		write(1, &n, 1);
	}
	if (nb >= 0 && nb < 10)
	{
		n = nb + 48;
		write(1, &n, 1);
	}
}

static int	ft_len(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int num)
{
	int		count;
	long	nb;

	nb = num;
	count = ft_len(nb);
	ft_digit(nb);
	return (count);
}
