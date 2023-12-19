/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexa_may_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:04:54 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/19 19:29:18 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hexamay(unsigned int n, int count, char *s)
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
		count = write_hexamay((n / 16), (count + 1), s);
	else
		count++;
	c = (n % 16);
	if (write (1, &s[c], 1) < 0)
		return (-1);
	return (count);
}

int	puthexa_may_c(int n)
{
	char	*s;
	int		count;

	count = 0;
	s = "0123456789ABCDEF";
	count = write_hexamay(n, count, s);
	return (count);
}
/* int	main()
{
	//printf("%x\n", -1);
	printf("\n%i", puthexa_may_c(-124));
	return (0);
} */