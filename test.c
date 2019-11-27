/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:13:17 by mli               #+#    #+#             */
/*   Updated: 2019/11/27 11:20:51 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int		main(void)
{
	//				%c				//
/*	printf("\n%d", ft_printf("%c", 'r'));
	printf("\n%d", ft_printf("%c", -142));
	printf("\n%d", ft_printf("%20c", -142));
	printf("\n%d", ft_printf("%-20c", -142));
	printf("\n%d", ft_printf("\nJust printing an r : %c\n", 'r'));
	printf("\n%d", ft_printf("Just printing ok : %c and %c !", 'o', 'k'));
*/	//				%s				//
	char r[] = {'1', '2', '3', '4', '5', '\0'};
	(void)r;
/*	printf("\n%d", ft_printf("%s", r));
	printf("\n%d", ft_printf("%.s", r));
	printf("\n%d", ft_printf("%.0s", r));
	printf("\n%d", ft_printf("%.3s", r));
	printf("\n%d", ft_printf("%.30s", r));
	printf("\n%d", ft_printf("%30.3s\n", r));
	printf("\n%d", ft_printf("%30.s\n", r));
	printf("\n%d", ft_printf("%-30.s\n", r));
	printf("\n%d", ft_printf("%-30s\n", r));
	printf("\n%d", ft_printf("%s %-30.3s %s\n", r, NULL, NULL));
*/
	//			%xX	&& *		//
/*	printf("\n%d", ft_printf("%20.15X\n", 2147483647));
	printf("\n%d", ft_printf("%-20.15X\n", 2147483647));
	printf("\n%d", ft_printf("%020.15X\n", 2147483647));
	printf("\n%d", ft_printf("%-*.*X\n", -20, -15, 2147483647));
	printf("\n%d", ft_printf("%*.*X\n", 20, -15, 2147483647));
	printf("\n%d", ft_printf("%*.*X\n", -20, -15, 2147483647));
	printf("\n%d", ft_printf("%0*.*X\n", -20, -15, 2147483647));
	printf("\n%d", ft_printf("%*.*X\n", -20, 15, -2147483647));
	printf("\n%d", ft_printf("%*.*X\n", -20, 15, -1));


*/
//	printf("%d\n", -2147483648);
//	printf("%.0005d\n", 132);
	return (0);
}
