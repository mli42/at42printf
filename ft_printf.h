/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:10:00 by mli               #+#    #+#             */
/*   Updated: 2019/11/19 17:21:31 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_printf
{
	char	flags;
	int		width;
	int		precision;
	char	type;
}				t_printf;

int		ft_printf(const char *, ...);

int		ft_is_handled(const char *str, int *i);
int		ft_small_atoi(const char *str, int *i);
char	ft_flags(const char *str, int *i);
int		ft_precision(const char *str, int *i);

char	*ft_convert(char *base, long int nbr);

#endif
