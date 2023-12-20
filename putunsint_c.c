/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsint_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:14:22 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/20 15:57:46 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunsint_c(unsigned int n, int count)
{
	char		c;

	if (n > 9)
	{
		count = putunsint_c(n / 10, count + 1);
		if (count < 0)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) < 0)
		return (-1);
	return (count);
}

/* int	main()
{
	void *p;

	//printf("\n%i", putunsint_c(-12345));
	printf ("%p", p);
	return (0);
} */
