/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:46:50 by mli               #+#    #+#             */
/*   Updated: 2019/11/21 11:56:37 by mli              ###   ########.fr       */
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
	char r[5] = {'1', '2', '3', '4', '5'};

	int returned;
	int returned1;

	(void)a;
	(void)b;
	(void)r;
	(void)returned;
	(void)returned1;

	returned = ft_printf("12345%00-06.4d\n", -15);
//	returned1= printf("%s\n", r);
	printf("and returns: %d\n", returned);
//	printf("and returns1: %d\n", returned1);
	return (0);
}
