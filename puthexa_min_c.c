/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexa_min_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:36:21 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/19 19:30:21 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hexamin(unsigned int n, int count, char *s)
{
	int	c;

	if (n < 0)
	{
		if (write (1, "-", 1) < 0)
			return (-1);
		n = -n;
		count++;
	}
	if (n > 15)
		count = write_hexamin((n / 16), (count + 1), s);
	else
		count++;
	c = (n % 16);
	if (write (1, &s[c], 1) < 0)
		return (-1);
	return (count);
}

int	puthexa_min_c(int n)
{
	char	*s;
	int		count;

	count = 0;
	s = "0123456789abcdef";
	count = write_hexamin(n, count, s);
	return (count);
}
/* int	main()
{
	//printf("%x\n", -1);
	printf("\n%d", puthexa_min_c(21474836));
	return (0);
}
 */