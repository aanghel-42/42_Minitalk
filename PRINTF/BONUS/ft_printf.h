/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:13:37 by pcatapan          #+#    #+#             */
/*   Updated: 2022/02/09 19:03:25 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	char	type;
	int		dot;
	int		hastag;
	int		space;
	int		par;
	int		plus;
	int		zero;
	int		less;
	int		less_par;
	int		num;
}	t_flag;

int	ft_printf(const char *str, ...);
int	ft_putchar(char lett);
int	ft_atoi(const char *str, int i, t_flag *flag);
int	ft_str(const char *str, int i, t_flag *flag);
int	ft_l(long nb, int base, t_flag *flag);
int	ft_putnb(int long long nbr, char *base, int l_base, t_flag *flag);
int	ft_putnb_p(unsigned long int nbr, char *base, int l_base, t_flag *flag);
int	ft_check_before(t_flag *f, int count);
int	ft_check_after(t_flag *flag, int count);

#endif