/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:29:02 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/20 18:50:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
