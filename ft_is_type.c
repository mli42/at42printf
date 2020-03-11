/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:12:15 by mli               #+#    #+#             */
/*   Updated: 2020/03/11 18:21:59 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	power_of_2(int y)
{
	return ((long int)1 << y);
}

void		ft_is_diux2(t_printf *args, int max, char *res, long int d)
{
	int			i;
	int			len;
	char		flags;
	const int	res_len = ft_strlen(res);

	i = 0;
	len = (args->precision > (res_len) ? args->precision : (res_len));
	flags = (args->precision >= 0 || args->flags != '0' ? ' ' : '0');
	if (args->flags == '-' && (d >= 0 ? 1 : write(1, "-", 1)))
		while (i++ < len - res_len)
			write(1, "0", 1);
	if (args->flags == '-')
		write(1, res, res_len);
	i = 0;
	if (flags == '0' && d < 0)
		write(1, "-", 1);
	while (i++ < max - len)
		write(1, &flags, 1);
	i = 0;
	if (args->flags != '-' && (d < 0 && flags != '0' ? write(1, "-", 1) : 1))
		while (i++ < len - res_len)
			write(1, "0", 1);
	if (args->flags != '-')
		write(1, res, res_len);
}

int			ft_is_diux(int *to_return, t_printf *args, long int d)
{
	int			len;
	int			max;
	int			res_len;
	char		*res;
	char		*base;

	len = 0;
	if (d == 0 && args->precision == 0)
		while (len++ < args->width)
			if (write(1, " ", 1) && ++(*to_return) && len == args->width)
				return (1);
	if (d == 0 && args->precision == 0)
		return (1);
	base = "0123456789";
	if (args->type == 'x' || args->type == 'X')
		base = (args->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	if (!(res = ft_convert(base, d * (d >= 0 ? 1 : -1))))
		return (-1);
	res_len = ft_strlen(res);
	len = (args->precision > (res_len) ? args->precision : (res_len));
	max = (args->width > len ? args->width : len);
	*to_return += max + (d < 0 && args->width < len + 1 ? 1 : 0);
	ft_is_diux2(args, (d >= 0 ? max : max - 1), res, d);
	free(res);
	return (1);
}

int			ft_is_ux(int *to_return, t_printf *args, unsigned long int u)
{
	u %= power_of_2((int)sizeof(unsigned int) * 8);
	return (ft_is_diux(to_return, args, u));
}
