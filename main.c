/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:46:50 by mli               #+#    #+#             */
/*   Updated: 2019/11/18 17:33:20 by mli              ###   ########.fr       */
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

//	int a = 1;
//	int *b = &a;

	returned = ft_printf("12345%6789", 1500000);
	printf("\nand returns: %d\n", returned);
	return (0);
}
