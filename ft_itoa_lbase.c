/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:33:41 by mli               #+#    #+#             */
/*   Updated: 2020/03/14 18:13:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen_base(long int nb, int base_len)
{
	int size;

	size = 0;
	if (nb <= 0)
		size++;
	while (nb != 0)
	{
		nb /= base_len;
		size++;
	}
	return (size);
}

char	*ft_itoa_lbase(const char *base, long int nbr)
{
	int			size;
	int			begin;
	char		*result;
	const int	base_len = ft_strlen(base);

	begin = (nbr >= 0 ? 0 : 1);
	size = ft_nbrlen_base(nbr, base_len);
	if (!(result = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
	}
	while (--size >= begin)
	{
		result[size] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (result);
}
