/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lpos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:33:41 by mli               #+#    #+#             */
/*   Updated: 2020/03/12 15:49:28 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen_base(long int nb, int base_len)
{
	int i;

	i = 1;
	while (nb >= base_len)
	{
		nb /= base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_lpos(char *base, long int nbr)
{
	int			size;
	long int	base_len;
	char		*result;

	base_len = ft_strlen(base);
	size = ft_nbrlen_base(nbr, base_len);
	if (!(result = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (--size >= 0)
	{
		result[size] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (result);
}
