/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:10:00 by mli               #+#    #+#             */
/*   Updated: 2019/11/18 15:22:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_printf
{
	char			flags;
	unsigned int	width;
	unsigned int	precision;
	char			type;
}				t_printf;

int		ft_printf(const char *, ...);
char	*ft_convert(char *base, long int nbr);

#endif
