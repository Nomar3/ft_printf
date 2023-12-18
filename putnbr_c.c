/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:18:30 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/18 13:38:37 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_nbr(int n, int count)
{
	char	c;

	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	if (n > 9)
		count = write_nbr((n / 10), ++count);
	c = (n % 10) + '0';
	write (1, &c, 1);
	return (count);
}

int	putnbr_c(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	else
		count = write_nbr(n, count);
	return (count);
}
/*int	main()
{
	printf("\n%i", putnbr_c(-1));
	return (0);
}*/