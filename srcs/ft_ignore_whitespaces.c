/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ignore_whitespaces.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:16:33 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/20 18:59:57 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_ignore_whitespaces(char *str)
{
	int		len;
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	out = malloc(sizeof(char) * (len + 1));
	while (str[i])
	{
		if (!ft_isspace(str[i]))
		{
			out[j] = str[i];
			j++;
		}
		i++;
	}
	out[j] = '\0';
	return (out);
}
