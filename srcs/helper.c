/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 19:31:34 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/20 20:11:24 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	scan_offset(char *str, char target, int limit)
{
	int i;

	i = 0;
	while (i < limit)
	{
		if (str[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

int	nearest_stage_0(char *str, int limit)
{
	int offset_plus;
	int offset_minus;

	offset_plus = scan_offset(str, '+', limit);
	offset_minus = scan_offset(str, '-', limit);
	return (offset_mins< offset_plus ? offset_minus : offset_plus);
}
