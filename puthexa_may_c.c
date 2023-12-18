/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexa_may_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:04:54 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/18 13:38:49 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hexamay(int n, int count, char *s)
{
	int	c;

	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	if (n > 15)
		count = write_hexamay((n / 16), (count + 1), s);
	else
		count++;
	c = (n % 16);
	write (1, &s[c], 1);
	return (count);
}

int	puthexa_may_c(int n)
{
	char	*s;
	int		count;

	count = 0;
	s = "0123456789ABCDEF";
	if (n == -2147483648)
	{
		write (1, "-80000000", 9);
		return (9);
	}
	else
		count = write_hexamay(n, count, s);
	return (count);
}
/* int	main()
{
	//printf("%x\n", -1);
	printf("\n%d", puthexa_may_c(21474836));
	return (0);
} */