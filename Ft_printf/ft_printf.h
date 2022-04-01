/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:40:57 by aanghel           #+#    #+#             */
/*   Updated: 2022/02/08 21:53:50 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_char(int lett);
unsigned int	ft_lenu(unsigned int num);
int				ft_u(unsigned int num);
unsigned int	ft_esa(unsigned int num, char lett);
int				ft_putnbr(int num);
int				ft_lenesa(uintptr_t nb);
int				ft_putesa(uintptr_t num);

#endif
