/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:12:15 by mli               #+#    #+#             */
/*   Updated: 2019/11/22 12:40:18 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int	power(int x, int puissance)
{
	int i;
	long int r;

	i = 0;
	r = 1;
	while (i++ < puissance)
		r *= x;
	return (r);
}

int		ft_is_c(int *to_return, t_printf *args, int c)
{
	int		i;
	char	flags;

	i = -1;
	flags = ' ';
	c %= power(2, ((int)sizeof(unsigned char) * 8));
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

#include <stdio.h>

int		ft_is_s(int *to_return, t_printf *args, char *str)
{
	int		i;
	int		len;
	int		max;
	char	flags;

	i = 0;
	len = 0;
	max = 0;
	flags = ' ';
	if (!str)
		str = "(null)";
	while (str[len] && (args->precision < 0 || args->precision > len))
		len++;
	printf("%d\n%s\n", len, str);
	(void)to_return;
	max = (args->width > len ? args->width : len);

	while (args->flags == '-' && i < len)
		write(1, &str[i++], 1);
	if (args->flags == '0')
		flags = '0';
	while (i < max - len)
	{
		write(1, &flags, 1);
		i++;
	}
	while (args->flags != '-' && i < max)
		write(1, &str[i++], 1);
	return (0);
}
/*
int		ft_is_p(int *to_return, t_printf *args, void *str)
{

	return (0);
}

int		ft_is_di(int *to_return, t_printf *args, long int d)
{

	return (0);
}

int		ft_is_u(int *to_return, t_printf *args, unsigned long int u)
{

	return (0);
}

int		ft_is_x(int *to_return, t_printf *args, unsigned long int x)
{

	return (0);
}

int		ft_is_percent(int *to_return, t_printf *args)
{

	return (0);
}*/
