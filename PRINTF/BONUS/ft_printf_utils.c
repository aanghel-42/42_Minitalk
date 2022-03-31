/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:19:41 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/10 16:04:41 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_l(long nb, int base, t_flag *flag)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0 && flag->type != 'u')
		nb = nb * -1;
	if (nb < 0 && flag->type == 'u')
		nb = 4294967296 - nb;
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int	ft_str(const char *str, int i, t_flag *flag)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	if (flag->dot == 1)
	{
		while (str[i] != '\0' && i < flag->num)
			count += ft_putchar(str[i++]);
	}
	else
	{
		while (str[i] != '\0' && flag->dot == 0)
			count += ft_putchar(str[i++]);
		if (count == 0 && flag->num > 0)
			count += ft_putchar(' ');
	}
	while (len < (flag->num - count) && flag->less == 1)
			len += ft_putchar(' ');
	return (count + len);
}

int	ft_putchar(char lett)
{
	write(1, &lett, 1);
	return (1);
}

/* + mette segno se positivo segno 
		| PUO essere seguito da numero (0)
		Funziona con - (d), (i)
*/
/* - mette spazi vuoti dopo il print
		| se n maggiore del count print
		| È sempre seguito da numero
		Funziona con - (i), (d), (p), (x), (X), (u)
*/
/* 0 è un numero mette spazi vuoti prima del print
		| se n maggiore del print
		Funziona con - (c), (d), (i), (u), (x), (X), (p)
*/
/* space mette uno spazio vuoto se numero è positivo
		|PUO essere seguita da numero (0) 
		Funziona con - (i), (d), 
*/
/* . precision, scrive tanti zeri in base al numero che lo segue
		|solo se count è minore del numero
		Funziona con - (s*), (i), (d), (x), (X)
		*s -> se precision è minore della stringa scrive fino a quella lunghezza
*/
/* # aggiunge 0x prima del print
		Funziona solo con (x), (X)
*/

int	ft_check_atoi(const char *str, int i, t_flag *f)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			f->less = 1;
		else
			f->plus = 1;
		i++;
	}
	if (str[i] == '.' || str[i] == ' ')
	{
		if (str[i] == '.')
			f->dot = 1;
		else if (str[i] == ' ')
			f->space = 1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str, int i, t_flag *f)
{
	int	j;

	j = 0;
	i = ft_check_atoi(str, i, f);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (f->space + f->dot + f->plus + f->less);
	if (str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9')
		f->zero += 1;
	while (str[i] >= '0' && str[i] <= '9')
		f->num = f->num * 10 + (str[i++] - '0');
	ft_check_atoi(str, i, f);
	j = f->space + f->less + f->plus + f->dot + f->zero + ft_l(f->num, 10, f);
	return (j);
}
