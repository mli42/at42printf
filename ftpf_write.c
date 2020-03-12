/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:32:37 by mli               #+#    #+#             */
/*   Updated: 2020/03/12 12:44:13 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_write(t_ftpf *ftpf, const char *str, size_t nb)
{
	ftpf->res += write(ftpf->fd, str, nb);
}

void	ftpf_write_n_char(t_ftpf *ftpf, const char c, size_t nb)
{
	size_t i;

	i = 0;
	while (i < nb)
	{
		ftpf->res += write(ftpf->fd, &c, 1);
		i++;
	}
}
