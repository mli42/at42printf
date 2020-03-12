/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:32:37 by mli               #+#    #+#             */
/*   Updated: 2020/03/12 14:33:35 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_write(t_ftpf *ftpf, const char *str, int nb)
{
	ftpf->res += write(ftpf->fd, str, nb);
	return (1);
}

int		ftpf_write_n_char(t_ftpf *ftpf, const char c, int nb)
{
	int i;

	i = -1;
	while (++i < nb)
		ftpf->res += write(ftpf->fd, &c, 1);
	return (1);
}
