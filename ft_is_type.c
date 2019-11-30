/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:12:15 by mli               #+#    #+#             */
/*   Updated: 2019/11/30 13:47:24 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int	power_of_2(int y)
{
	return ((unsigned long int)1 << y);
}

void				ft_is_x2(t_printf *args, int len, int max, char *res)
{
	int		i;
	int		res_len;
	char	flags;

	i = 0;
	res_len = ft_strlen(res);
	flags = (args->flags == '0' ? '0' : ' ');
	flags = (args->precision >= 0 ? ' ' : flags);
	if (args->flags == '-')
	{
		while (i++ < len - res_len)
			write(1, "0", 1);
		write(1, res, res_len);
	}
	i = 0;
	while (i++ < max - len)
		write(1, &flags, 1);
	i = 0;
	if (args->flags != '-')
	{
		while (i++ < len - res_len)
			write(1, "0", 1);
		write(1, res, res_len);
	}
}

int					ft_is_x(int *to_return, t_printf *args, unsigned long int x)
{
	int		len;
	int		max;
	int		res_len;
	char	*res;

	if (!(res = ft_convert((args->type == 'X' ? "0123456789ABCDEF" :
		"0123456789abcdef"), x % power_of_2((int)sizeof(unsigned int) * 8))))
		return (-1);
	res_len = ft_strlen(res);
	len = (args->precision > (res_len) ? args->precision : (res_len));
	max = (args->width > len ? args->width : len);
	*to_return += max;
	ft_is_x2(args, len, max, res);
	free(res);
	return (1);
}

void				ft_is_di2(t_printf *args, int max, char *res, long int d)
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
	while (i++ < max - len)
		write(1, &flags, 1);
	i = 0;
	if (args->flags != '-' && (d >= 0 ? 1 : write(1, "-", 1)))
		while (i++ < len - res_len)
			write(1, "0", 1);
	if (args->flags != '-')
		write(1, res, res_len);
}

int					ft_is_di(int *to_return, t_printf *args, long int d)
{
	int			len;
	int			max;
	int			res_len;
	char		*res;

	len = 0;
	if (d == 0 && args->precision == 0)
		while (len++ < args->width)
			if (write(1, " ", 1) && ++(*to_return) && len == args->width)
				return (1);
	if (d == 0 && args->precision == 0)
		return (1);
	if (!(res = ft_convert("0123456789",
					(unsigned long int)d * (d >= 0 ? 1 : -1))))
		return (-1);
	res_len = ft_strlen(res);
	len = (args->precision > (res_len) ? args->precision : (res_len));
	max = (args->width > len ? args->width : len);
	*to_return += max + (d < 0 && args->width < len + 1 ? 1 : 0);
	ft_is_di2(args, (d >= 0 ? max : max - 1), res, d);
	free(res);
	return (1);
}
