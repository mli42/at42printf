/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:09:39 by mli               #+#    #+#             */
/*   Updated: 2020/03/12 12:28:56 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_type(t_ftpf *ftpf, va_list ap, t_printf *args)
{
	int		result;

	result = 0;
	if (args->type == 'c')
		result = ft_is_c(ftpf, args, va_arg(ap, int));
	else if (args->type == 's')
		result = ft_is_s(ftpf, args, va_arg(ap, char *));
	else if ((args->type == 'x') || (args->type == 'X') || (args->type == 'u'))
		result = ft_is_ux(ftpf, args, va_arg(ap, unsigned int));
	else if (args->type == 'p')
		result = ft_is_p(ftpf, args, va_arg(ap, void *));
	else if ((args->type == 'd') || (args->type == 'i'))
		result = ft_is_diux(ftpf, args, (int)va_arg(ap, int));
	else if (args->type == '%')
		result = ft_is_c(ftpf, args, '%');
	return (result);
}

int		ft_found_conv(const char *str, int *i, t_ftpf *ftpf, va_list ap)
{
	t_printf	args;

	(*i)++;
	args.flags = ft_flags(str, i);
	args.width = ft_small_atoi(str, i, ap, &args);
	args.precision = ft_precision(str, i, ap, &args);
	if (((args.type = ft_is_handled(str, i)) < 0) ||
		(ftpf_type(ftpf, ap, &args) == -1))
		return (0);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	ap;
	t_ftpf	ftpf;

	i = 0;
	ftpf.fd = 1;
	ftpf.res = 0;
	va_start(ap, str);
	while (str[i] && ftpf.res >= 0)
	{
		j = 0;
		while (str[i] && str[i] != '%' && str[i] != '{')
		{
			i++;
			j++;
		}
		if (j)
			ftpf.res += write(1, &str[i - j], j);
		if ((str[i] == '%' && !ft_found_conv(str, &i, &ftpf, ap)) ||
			(str[i] == '{' && 0))
			ftpf.res = -1;
	}
	va_end(ap);
	return (ftpf.res);
}
