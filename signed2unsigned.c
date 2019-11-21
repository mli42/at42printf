/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:13:17 by mli               #+#    #+#             */
/*   Updated: 2019/11/21 14:08:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

unsigned long int	power(int x, int puissance)
{
	int i;
	long int r;

	i = 0;
	r = 1;
	while (i++ < puissance)
		r *= x;
	return (r);
}

int		main(void)
{
	int a = -20;
	long int b = a + 4294967295 + 1;
	unsigned int c;

	c = a % power(2, ((int)sizeof(unsigned int) * 8));
	printf("%u\n", a);
	printf("%ld\n", b);
	printf("%ld\n", (long int)c);
	printf("%d\n", (int)sizeof(unsigned int));
	printf("%ld\n", power(2, ((int)sizeof(unsigned int) * 8)));
	return (0);
}
