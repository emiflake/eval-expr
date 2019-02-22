/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:52:21 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/20 18:53:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
