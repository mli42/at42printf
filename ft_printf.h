/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:10:00 by mli               #+#    #+#             */
/*   Updated: 2019/12/01 17:23:24 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_printf
{
	char	flags;
	int		width;
	int		precision;
	char	type;
}					t_printf;

int					ft_printf(const char *str, ...);

unsigned long int	power_of_2(int y);
int					ft_is_handled(const char *str, int *i);
int					ft_small_atoi(const char *str, int *i,
						va_list ap, t_printf *args);
char				ft_flags(const char *str, int *i);
int					ft_precision(const char *str, int *i,
						va_list ap, t_printf *args);

int					ft_is_c(int *to_return, t_printf *args, int c);
int					ft_is_s(int *to_return, t_printf *args, char *str);
int					ft_is_p(int *to_return, t_printf *args, void *str);
int					ft_is_di(int *to_return, t_printf *args, long int d);
int					ft_is_u(int *to_return, t_printf *args,
							unsigned long int u);
int					ft_is_x(int *to_return, t_printf *args,
							unsigned long int x);
int					ft_is_percent(int *to_return, t_printf *args);

char				*ft_convert(char *base, long int nbr);
int					ft_strlen(const char *str);

#endif
