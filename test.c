/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:13:17 by mli               #+#    #+#             */
/*   Updated: 2019/11/30 12:10:20 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int		main(void)
{
	//				%c				//
/*	ft_printf("||Returned: %d ||\n\n", ft_printf("%c", 'r'));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%c", -142));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%20c", -142));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%-20c", -142));
	ft_printf("||Returned: %d ||\n\n", ft_printf("\nJust printing an r : %c\n", 'r'));
	ft_printf("||Returned: %d ||\n\n", ft_printf("Just printing ok : %c and %c !", 'o', 'k'));
*/	//				%s				//
	char r[] = {'1', '2', '3', '4', '5', '\0'};
	char r2[] = {'1', '2', '3', '4', '5'};
	(void)r;
	(void)r2;
/*	ft_printf("||Returned: %d ||\n\n", ft_printf("%s", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.s", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.0s", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.3s", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.3s", r2));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.30s", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%30.3s\n", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%30.s\n", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%-30.s\n", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%-30s\n", r));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%s %-30.3s %s\n", r, NULL, NULL));
*/
	//			%xX	&& *		//
/*	ft_printf("||Returned: %d ||\n\n", ft_printf("%20.15X\n", 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%-20.15X\n", 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%020.15X\n", 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%-*.*X\n", -20, -15, 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%*.*X\n", 20, -15, 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%*.*X\n", -20, -15, 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%0*.*X\n", -20, -15, 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%*.*X\n", -20, 15, -2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%*.*X\n", -20, 15, -1));

	ft_printf("||Returned: %d ||\n\n", ft_printf("%*.*X\n", -20, 15, -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.*X\n", 15, -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%*X\n", -20, -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%*X\n", 20, -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%X\n", -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%x\n", -123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%x\n", 123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%x\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.3x\n", 123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%3x\n", 123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%020.15x\n", -2147483647 - 1));
*/
	//				%p	 		//
	int	a = 5;
	(void)a;
/*	ft_printf("||Returned: %d ||\n\n", ft_printf("%p\n", &a));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%20p\n", &a));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%-20p\n", &a));
*/
	//			%d				//

	// Basics
	ft_printf("||Returned: %d ||\n\n", ft_printf("%d\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%d\n", 123456));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%d\n", -123456));

	// Comptage du -
	ft_printf("||Returned: %d ||\n\n", ft_printf("%d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%1d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%2d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%3d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%4d\n", -1));

	// Bon placement du -
	ft_printf("||Returned: %d ||\n\n", ft_printf("%020.15d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%20.15d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%-20.15d\n", -123));

	// Int max et min
	ft_printf("||Returned: %d ||\n\n", ft_printf("%d\n", 2147483647));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%d\n", -2147483647 - 1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%020.15d\n", -2147483647 - 1));

	// When 0
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.d\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%20.d\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%020d\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%-20d\n", 0));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%20d\n", 0));

	// Parsing
	ft_printf("||Returned: %d ||\n\n", ft_printf("%00000000004d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%00000-00004d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%----------4d\n", -1));
	ft_printf("||Returned: %d ||\n\n", ft_printf("%.0005d\n", 132));

	return (0);
}
