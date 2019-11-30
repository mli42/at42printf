/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:45:09 by mli               #+#    #+#             */
/*   Updated: 2019/11/30 13:47:08 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
