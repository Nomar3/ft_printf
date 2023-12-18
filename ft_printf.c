/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:08:08 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/18 23:34:33 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	format_print(char s, va_list args)
{
	if (s == 'c')
		return (putchar_c(va_arg(args, char)));
	else if (s == 's')
		return (putstr_c(va_arg(args, char *)));
	else if (s == 'p')
		return (putptr_c(va_arg(args, void *)));
	else if (s == 'd' || s == 'i')
		return (putnbr_c(va_arg(args, int)));
	else if (s == 'u')
		return (putunsint_c(va_arg(args, unsigned int)));
	else if (s == 'x')
		return (puthexa_min_c(va_arg(args, int)));
	else if (s == 'X')
		return (puthexa_may_c(va_arg(args, int)));
	else if (s == '%')
	{
		write(1, "%", 1);
		return (1);
	}
}

int	ft_printf(char const *s, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && tipe_finder(s[i + 1]))
			count += format_print(s[++i], args);
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	main()
{
	void *p;
	
	printf("\n%i", (ft_printf("pito %p", p)));
	return 0;
}
