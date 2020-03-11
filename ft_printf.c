/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:09:39 by mli               #+#    #+#             */
/*   Updated: 2020/03/11 18:22:16 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(int *to_return, va_list ap, t_printf *args)
{
	int		result;

	result = 0;
	if (args->type == 'c')
		result = ft_is_c(to_return, args, va_arg(ap, int));
	else if (args->type == 's')
		result = ft_is_s(to_return, args, va_arg(ap, char *));
	else if ((args->type == 'x') || (args->type == 'X') || (args->type == 'u'))
		result = ft_is_ux(to_return, args, va_arg(ap, unsigned int));
	else if (args->type == 'p')
		result = ft_is_p(to_return, args, va_arg(ap, void *));
	else if ((args->type == 'd') || (args->type == 'i'))
		result = ft_is_diux(to_return, args, (int)va_arg(ap, int));
	else if (args->type == '%')
		result = ft_is_c(to_return, args, '%');
	return (result);
}

int		ft_found(const char *str, int *i, int *to_return, va_list ap)
{
	t_printf	args;

	(*i)++;
	args.flags = ft_flags(str, i);
	args.width = ft_small_atoi(str, i, ap, &args);
	args.precision = ft_precision(str, i, ap, &args);
	if (((args.type = ft_is_handled(str, i)) < 0) ||
		(ft_type(to_return, ap, &args) == -1))
		return (0);
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
		while (str[i] && str[i] != '%' && str[i] != '{')
		{
			i++;
			j++;
		}
		if (j)
			to_return += write(1, &str[i - j], j);
		if ((str[i] == '%' && !ft_found(str, &i, &to_return, ap)) ||
			(str[i] == '{' && 0))
			to_return = -1;
	}
	va_end(ap);
	return (to_return);
}
