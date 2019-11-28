/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:33:41 by mli               #+#    #+#             */
/*   Updated: 2019/11/28 11:55:27 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		result_size(long int nb, long int base_len)
{
	int i;

	i = 1;
	while (nb >= base_len)
	{
		nb /= base_len;
		i++;
	}
	return (i + 1);
}

void	ft_swap(char *r, int max)
{
	int i;
	int swap;

	i = 0;
	while (i < max)
	{
		swap = r[i];
		r[i++] = r[max];
		r[max--] = swap;
	}
}

char	*ft_convert(char *base, long int nbr)
{
	int			i;
	int			size;
	long int	base_len;
	char		*result;

	i = 0;
	base_len = ft_strlen(base);
	size = result_size(nbr, base_len);
	if (!(result = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (nbr >= base_len)
	{
		result[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	result[i] = base[nbr % base_len];
	result[i + 1] = '\0';
	ft_swap(result, i);
	return (result);
}
