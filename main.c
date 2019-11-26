/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:46:50 by mli               #+#    #+#             */
/*   Updated: 2019/11/26 19:43:16 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "ft_printf.h"

int		main(void)
{
	int a = 1;
	int *b = &a;
	char r[] = {'1', '2', '3', '4', '5', '\0'};

	int returned;
	int returned1;

	(void)a;
	(void)b;
	(void)r;
	(void)returned;
	(void)returned1;

//	returned = ft_printf("what %*s up\n", -2147483648, r);
//	returned1 = printf("%--d\n", 1);
	returned = ft_printf("%20.15X\n", 2147483647);
	returned1 = printf("%20.15X\n", 2147483647);
	printf("Mine: %d\n", returned);
	printf("True: %d\n", returned1);
	return (0);
}
