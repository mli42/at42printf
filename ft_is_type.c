/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:12:15 by mli               #+#    #+#             */
/*   Updated: 2019/11/24 10:30:09 by mli              ###   ########.fr       */
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

int		ft_is_s(int *to_return, t_printf *args, char *str)
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
	while (str[len] && (args->precision < 0 || args->precision > len))
		len++;
	max = (args->width > len ? args->width : len);
	if (args->flags == '-')
		write(1, &str[0], len);
	while(i++ < max - len)
		write(1, &flags, 1);
	if (args->flags != '-')
		write(1, &str[0], len);
	*to_return += max;
	return (1);
}

#include <stdio.h>

int		ft_is_x(int *to_return, t_printf *args, long int x)
{
	char	*base;
	char	*result;

	(void)to_return;
	x %= power(2, ((int)sizeof(unsigned long int) * 8));
	base = (args->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	if (!(result = ft_convert(base, x)))
		return (-1);

//	printf("%s\n", result);

	free(result);
	return (1);
}
/*
int		ft_is_p(int *to_return, t_printf *args, void *str)
{
	return (ft_is_x(to_return, args, (unsigned long int)str));
}

int		ft_is_di(int *to_return, t_printf *args, long int d)
{

	return (0);
}

int		ft_is_u(int *to_return, t_printf *args, unsigned long int u)
{

	return (0);
}


int		ft_is_percent(int *to_return, t_printf *args)
{

	return (0);
}*/
