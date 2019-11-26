/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:17:59 by mli               #+#    #+#             */
/*   Updated: 2019/11/26 16:26:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_handled(const char *str, int *i)
{
	int		k;
	char	*can_convert;

	k = -1;
	can_convert = "cspdiuxX%";
	while (can_convert[++k])
		if (can_convert[k] == str[*i])
		{
			(*i)++;
			return (can_convert[k]);
		}
	return (-1);
}

int		ft_small_atoi(const char *str, int *i, va_list ap, t_printf *args)
{
	long int result;

	if (str[*i] == '*')
	{
		(*i)++;
		if ((result = va_arg(ap, int)) < 0)
		{
			result *= -1;
			args->flags = '-';
		}
		return ((int)result);
	}
	result = ((str[*i] >= '0' && str[*i] <= '9') ? 0 : -1);
	while (str[*i] >= '0' && str[*i] <= '9')
		result = (10 * result) + str[(*i)++] - '0';
	return (result);
}

char	ft_flags(const char *str, int *i)
{
	char	result;

	result = -1;
	while (str[*i] == '0' || str[*i] == '-')
	{
		if (!(str[*i] == '0' && result == '-'))
			result = str[*i];
		(*i)++;
	}
	return (result);
}

int		ft_precision(const char *str, int *i, va_list ap, t_printf *args)
{
	int result;

	result = -1;
	if (str[*i] == '.')
	{
		(*i)++;
		if ((result = ft_small_atoi(str, i, ap, args)) == -1)
			result = 0;
	}
	return (result);
}
