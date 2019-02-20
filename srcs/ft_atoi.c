/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cedrak <cedrak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:05:30 by cedrak        #+#    #+#                 */
/*   Updated: 2019/02/20 18:24:53 by cedrak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include <ft.h>

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

char	*ft_skip_whitespaces(char *str)
{
	while (ft_isspace(*str) || *str == '\0')
		str++;
	return (str);
}

int		ft_atoi(char *s)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	s = ft_skip_whitespaces(s);
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * result);
}
