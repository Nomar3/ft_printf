/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tipe_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:59:00 by rmarin-j          #+#    #+#             */
/*   Updated: 2023/12/18 23:05:34 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*tipe_finder(char c)
{
	char	*p;

	p = "cspdiuxX%";
	while (*p != c && *p != '\0')
		p++;
	if (*p == c)
		return (p);
	return (0);
}