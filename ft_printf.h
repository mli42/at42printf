/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:10:00 by mli               #+#    #+#             */
/*   Updated: 2020/03/12 12:44:57 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ftpf_struct.h"
# include "meine_liebe/libft.h"

int			ft_printf(const char *str, ...);

long int	power_of_2(int y);
int			ft_is_handled(const char *str, int *i);
int			ft_small_atoi(const char *str, int *i, va_list ap, t_printf *args);
char		ft_flags(const char *str, int *i);
int			ft_precision(const char *str, int *i, va_list ap, t_printf *args);

int			ft_is_c(t_ftpf *ftpf, t_printf *args, int c);
int			ft_is_s(t_ftpf *ftpf, t_printf *args, char *str);
int			ft_is_p(t_ftpf *ftpf, t_printf *args, void *str);
int			ft_is_diux(t_ftpf *ftpf, t_printf *args, long int d);
int			ft_is_ux(t_ftpf *ftpf, t_printf *args, unsigned long int u);

char		*ft_convert(char *base, long int nbr);

void		ftpf_write(t_ftpf *ftpf, const char *str, size_t nb);
void		ftpf_write_n_char(t_ftpf *ftpf, const char c, size_t nb);

#endif
