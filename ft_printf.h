/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:55:23 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/18 23:05:48 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(char const *, ...);
char	*tipe_finder(char c);
int		putchar_c(char c);
int		putstr_c(char *s);
int		putnbr_c(int n);
int		puthexa_min_c(int n);
int		puthexa_may_c(int n);
int		putunsint_c(unsigned int n);
int		putptr_c(unsigned long ptr);

#endif
