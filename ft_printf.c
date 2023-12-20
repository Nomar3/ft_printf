/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:08:08 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/20 15:57:16 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_print(char s, va_list args)
{
	if (s == 'c')
		return (putchar_c(va_arg(args, int)));
	else if (s == 's')
		return (putstr_c(va_arg(args, char *)));
	else if (s == 'p')
		return (putptr_c(va_arg(args, unsigned long)));
	else if (s == 'd' || s == 'i')
		return (putnbr_c(va_arg(args, int)));
	else if (s == 'u')
		return (putunsint_c(va_arg(args, unsigned int), 1));
	else if (s == 'x')
		return (puthexa_min_c(va_arg(args, int)));
	else if (s == 'X')
		return (puthexa_may_c(va_arg(args, int)));
	else if (s == '%')
		return (putchar_c('%'));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			args;
	int				f;

	i = -1;
	count = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && tipe_finder(s[i + 1]))
		{
			f = format_print(s[++i], args);
			if (f < 0)
				return (-1);
			count += f - 1;
		}
		else
			if (write(1, &s[i], 1) < 0)
				return (-1);
		count++;
	}
	va_end(args);
	return (count);
}

/* int	main()
{
	
	printf("\n%i", (ft_printf(" %p ", -1)));
	printf (" %p ", -1);
	return 0;
}
 */