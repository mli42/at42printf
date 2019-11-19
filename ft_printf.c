/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:09:39 by mli               #+#    #+#             */
/*   Updated: 2019/11/19 18:06:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

int		ft_found(const char *str, int *i, int *to_return, va_list ap)
{
	t_printf	*args;
	char		*result;

	if (!(args = (t_printf *)malloc(sizeof(t_printf))))
		return (-1);
	(*i)++;
	args->flags = ft_flags(str, i);
	args->width = ft_small_atoi(str, i);
	args->precision = ft_precision(str, i);
	if ((args->type = ft_is_handled(str, i)) < 0)
	{
		free(args);
		return (-1);
	}
	if (args->precision == 0)
	{
		free(args);
		return (1);
	}
	// result = ft_result(va_list ap);
	// to_return += ft_strlen(result);
	(void)result;
	(void)ap;
	(void)to_return;

	printf("\nFlags:%c\n", (args->flags > 0 ? args->flags : 'N'));
	printf("Width:%d\n", args->width);
	printf("Precision:%d\n", args->precision);
	printf("Convert:%c\n", args->type);


	free(args);
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
