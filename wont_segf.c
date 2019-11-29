/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wont_segf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:59:52 by mli               #+#    #+#             */
/*   Updated: 2019/11/29 11:58:37 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int				ft_printf(const char *str, ...);

int		main(void)
{
	char r[] = {'1', '2', '3', '4', '5'};

	printf("%0c", 'r');
	printf("%.10c", 'r');
	printf("%-0.10c", 'r');

	printf("%s\n");
	printf("%.s\n", 42);
	printf("%.30s\n", r);

	printf("%.30p\n", r);
}
