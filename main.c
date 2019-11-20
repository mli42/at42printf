/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:46:50 by mli               #+#    #+#             */
/*   Updated: 2019/11/20 16:16:27 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "ft_printf.h"

int		main(void)
{
	int returned;
	int returned1;

	(void)returned;
//	(void)returned1;

	int a = 1;
	int *b = &a;

//	returned = ft_printf("12345%00-06.4%\n", 1500000);
	returned1= printf("%X\n", -10);
//	printf("and returns: %d\n", returned);
	printf("and returns1: %d\n", returned1);
	return (0);
}
