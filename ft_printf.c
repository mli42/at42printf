/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:09:39 by mli               #+#    #+#             */
/*   Updated: 2019/11/18 17:34:19 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>


int		ft_found(const char *str, int *i, int *to_return, va_list ap)
{
	(*i)++;

	return (1);
}


int		ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		to_return;
	va_list	ap;

	i = 0;
	to_return = 0;
	va_start(ap, str);
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] != '%')
		{
			i++;
			j++;
			to_return++;
		}
		if (j)
			write(1, &str[i - j], j);
		if (str[i] == '%')
			if (!(ft_found(str, &i, &to_return, ap)))
				return (-1);
	}
	va_end(ap);
	return (to_return);
}
