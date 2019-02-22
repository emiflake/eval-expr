/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:55:29 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/20 18:56:21 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_putnbr(int n)
{
	long int t;

	t = n;
	if (t < 0)
	{
		ft_putchar('-');
		t = -t;
	}
	if (t / 10)
	{
		ft_putnbr(t / 10);
	}
	ft_putchar(t % 10 + '0');
}
