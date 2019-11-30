/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:12:15 by mli               #+#    #+#             */
/*   Updated: 2019/11/30 12:34:28 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int	power_of_2(int y)
{
	return ((unsigned long int)1 << y);
}

int					ft_is_c(int *to_return, t_printf *args, int c)
{
	int		i;
	char	flags;

	i = -1;
	flags = ' ';
	c %= power_of_2((int)sizeof(unsigned char) * 8);
	if (args->flags == '-')
		write(1, &c, 1);
	if (args->flags == '0')
		flags = '0';
	while (++i < args->width - 1)
		write(1, &flags, 1);
	if (args->flags != '-')
		write(1, &c, 1);
	*to_return += i + 1;
	return (1);
}

int					ft_is_s(int *to_return, t_printf *args, char *str)
{
	int		i;
	int		len;
	int		max;
	char	flags;

	i = 0;
	len = 0;
	flags = (args->flags == '0' ? '0' : ' ');
	if (!str)
		str = "(null)";
	while ((args->precision < 0 || args->precision > len) && str[len])
		len++;
	max = (args->width > len ? args->width : len);
	if (args->flags == '-')
		write(1, &str[0], len);
	while (i++ < max - len)
		write(1, &flags, 1);
	if (args->flags != '-')
		write(1, &str[0], len);
	*to_return += max;
	return (1);
}

#include <stdio.h>

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

int					ft_is_p(int *to_return, t_printf *args, void *str)
{
	int		i;
	int		len;
	int		max;
	char	*res;

	if (!(res = ft_convert("0123456789abcdef", (unsigned long int)str)))
		return (-1);
	len = ft_strlen(res) + 2;
	max = (args->width > len ? args->width : len);
	*to_return += max;
	if (args->flags == '-')
		if (write(1, "0x", 2))
			write(1, res, len - 2);
	i = 0;
	while (i++ < max - len)
		write(1, " ", 1);
	if (args->flags != '-')
		if (write(1, "0x", 2))
			write(1, res, len - 2);
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

int					ft_is_u(int *to_return, t_printf *args, unsigned long int u)
{
	u %= power_of_2((int)sizeof(unsigned int) * 8);
	return (ft_is_di(to_return, args, u));
}

int					ft_is_percent(int *to_return, t_printf *args)
{
	ft_is_c(to_return, args, '%');
	return (1);
}
