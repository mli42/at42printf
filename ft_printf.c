/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:09:39 by mli               #+#    #+#             */
/*   Updated: 2019/11/26 16:38:47 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_c(int *to_return, t_printf *args, int c);
int		ft_is_s(int *to_return, t_printf *args, char *str);
int		ft_is_p(int *to_return, t_printf *args, void *str);
int		ft_is_di(int *to_return, t_printf *args, long int d);
int		ft_is_u(int *to_return, t_printf *args, unsigned long int u);
int		ft_is_x(int *to_return, t_printf *args, unsigned long int x);
int		ft_is_percent(int *to_return, t_printf *args);

#include <stdio.h>

int		ft_found(const char *str, int *i, int *to_return, va_list ap)
{
	t_printf	*args;
	int			result;

	if (!(args = (t_printf *)malloc(sizeof(t_printf))))
		return (-1);
	(*i)++;
	args->flags = ft_flags(str, i);
	args->width = ft_small_atoi(str, i, ap, args);
	args->precision = ft_precision(str, i, ap, args);
	if ((args->type = ft_is_handled(str, i)) < 0)
	{
		free(args);
		return (-1);
	}
	result = 0;

/*	printf("\nFlags:%c\n", (args->flags > 0 ? args->flags : 'N'));
	printf("Width:%d\n", args->width);
	printf("Precision:%d\n", args->precision);
	printf("Convert:%c\n", args->type);*/

	if (args->type == 'c')
		result = ft_is_c(to_return, args, va_arg(ap, int));
	else if (args->type == 's')
		result = ft_is_s(to_return, args, va_arg(ap, char *));
	else if ((args->type == 'x') || (args->type == 'X'))
		result = ft_is_x(to_return, args, va_arg(ap, unsigned long int));
/*	else if (args->type == 'p')
		result = ft_is_p(to_return, args, va_arg(ap, void *));
	else if ((args->type == 'd') || (args->type == 'i'))
		result = ft_is_di(to_return, args, va_arg(ap, long int));
	else if (args->type == 'u')
		result = ft_is_u(to_return, args, va_arg(ap, unsigned long int));
	else if (args->type == '%')
		result = ft_is_percent(to_return, args);*/
	if (result == -1)
		*to_return = (-1);
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
	while (str[i] && to_return >= 0)
	{
		j = 0;
		while (str[i] && str[i] != '%')
		{
			i++;
			j++;
		}
		if (j)
			to_return += write(1, &str[i - j], j);
		if (str[i] == '%')
			if (!(ft_found(str, &i, &to_return, ap)))
				to_return = -1;
	}
	va_end(ap);
	return (to_return);
}
