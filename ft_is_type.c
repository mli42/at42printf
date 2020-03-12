/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:12:15 by mli               #+#    #+#             */
/*   Updated: 2020/03/12 14:44:41 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	power_of_2(int y)
{
	return (1L << y);
}

void		ft_is_diux2(t_printf *args, t_ftpf *ftpf, char *res, long int d)
{
	int			len;
	int			max;
	char		flags;
	const int	res_len = ft_strlen(res);

	len = (args->precision > res_len ? args->precision : res_len);
	max = (args->width > len ? args->width : len) - (d < 0 ? 1 : 0);
	flags = (args->precision >= 0 || args->flags != '0' ? ' ' : '0');
	if (args->flags == '-')
	{
		if (d < 0)
			ftpf_write_n_char(ftpf, '-', 1);
		ftpf_write_n_char(ftpf, '0', len - res_len);
		ftpf_write(ftpf, res, res_len);
	}
	if (flags == '0' && d < 0)
		ftpf_write_n_char(ftpf, '-', 1);
	ftpf_write_n_char(ftpf, flags, max - len);
	if (args->flags != '-')
	{
		if (d < 0 && flags != '0')
			ftpf_write_n_char(ftpf, '-', 1);
		ftpf_write_n_char(ftpf, '0', len - res_len);
		ftpf_write(ftpf, res, res_len);
	}
}

int			ft_is_diux(t_ftpf *ftpf, t_printf *args, long int d)
{
	char		*res;
	char		*base;

	if (d == 0 && args->precision == 0)
		return (ftpf_write_n_char(ftpf, ' ', args->width));
	base = "0123456789";
	if (args->type == 'x' || args->type == 'X')
		base = (args->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	if (!(res = ft_convert(base, d * (d >= 0 ? 1 : -1))))
		return (-1);
	ft_is_diux2(args, ftpf, res, d);
	free(res);
	return (1);
}

int			ft_is_ux(t_ftpf *ftpf, t_printf *args, unsigned long int u)
{
	u %= power_of_2((int)sizeof(unsigned int) * 8);
	return (ft_is_diux(ftpf, args, u));
}
