/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:46:50 by mli               #+#    #+#             */
/*   Updated: 2019/11/27 17:17:44 by mli              ###   ########.fr       */
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

	returned = ft_printf("%p\n", &a);
	returned1 = printf("%p\n", &a);

	printf("Mine: %d\n", returned);
	printf("True: %d\n", returned1);
	return (0);
}
