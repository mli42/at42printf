/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:46:50 by mli               #+#    #+#             */
/*   Updated: 2019/11/29 18:34:01 by mli              ###   ########.fr       */
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

	int returned = 0;
	int returned1 = 0;

	(void)a;
	(void)b;
	(void)r;
	(void)returned;
	(void)returned1;

//	returned1 = printf("%030d\n", -123456);

//	returned = ft_printf("%020.15d\n", -1);
//	returned1 = printf("%020.15d\n", -1);

//	printf("%20.d\n", 0);
//	ft_printf("%20.d\n", 0);
//	ft_printf("%.d\n", 0);
//	ft_printf("%20.d\n", 0);

//	returned = ft_printf("%d\n", -1);
//	returned1 = printf("%d\n", -1);

	returned = ft_printf("%.d\n", 0);
	returned1 = printf("%.d\n", 0);

	printf("Mine: %d\n", returned);
	printf("True: %d\n", returned1);
	return (0);
}
