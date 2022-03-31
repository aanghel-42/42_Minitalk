/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:57:14 by aanghel           #+#    #+#             */
/*   Updated: 2022/02/07 23:49:08 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_digitupper(unsigned int nb, char *base)
{
	if (nb >= 16)
	{
		ft_digitupper(nb / 16, base);
		ft_char(base[nb % 16]);
	}
	else if (nb >= 0)
	{
		ft_char(base[nb % 16]);
	}
}

static void	ft_digitlower(unsigned int nb, char *base)
{
	if (nb >= 16)
	{
		ft_digitlower(nb / 16, base);
		ft_char(base[nb % 16]);
	}
	else if (nb >= 0)
	{
		ft_char(base[nb % 16]);
	}
}

unsigned int	ft_esa(unsigned int num, char lett)
{
	int		count;
	char	*base;

	count = ft_lenesa(num);
	if (lett == 'X')
	{
		base = "0123456789ABCDEF";
		ft_digitupper(num, base);
	}
	else
	{
		base = "0123456789abcdef";
		ft_digitlower(num, base);
	}
	return (count);
}
