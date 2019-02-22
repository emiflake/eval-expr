/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:17:03 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/20 18:26:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
