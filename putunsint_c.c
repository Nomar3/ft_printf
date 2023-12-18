/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsint_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:14:22 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/18 18:43:25 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunsint_c(unsigned int n)
{
	char	c;
	int		count;

	count = 1;
	if (n > 9)
		count += putunsint_c(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count);
}

/* int	main()
{
	void *p;

	//printf("\n%i", putunsint_c(-12345));
	printf ("%p", p);
	return (0);
} */
