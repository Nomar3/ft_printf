/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:00:54 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/18 18:43:14 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_ptr(unsigned long ptr, int count, char *s)
{
	int	c;

	if (ptr > 15)
		count = write_ptr((ptr / 16), (count + 1), s);
	else
		count++;
	c = (ptr % 16);
	write (1, &s[c], 1);
	return (count);
}

int	putptr_c(unsigned long ptr)
{
	char	*s;
	int		count;

	count = 2;
	write (1, "0x", 2);
	s = "0123456789abcdf";
	count = write_ptr(ptr, count, s);
	return (count);
}

/* int	main()
{
	void *p;

	printf("\n%i", putptr_c(p));
	return (0);
}
 */