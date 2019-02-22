/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:57:52 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/22 13:24:57 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	eval_stage_2(char **str)
{
	int result;

	result = 0;
	if (**str == '(')
	{
		(*str)++;
		result = eval_stage_0(str);
		(*str)++;
	}
	else
		while (**str >= '0' && **str <= '9')
			result = result * 10 + *(*str)++ - '0';
	return (result);
}

int	eval_stage_1(char **str)
{
	int result;

	result = eval_stage_2(str);
	while (**str == '*' || **str == '/' || **str == '%')
	{
		if (**str == '*')
		{
			(*str)++;
			result *= eval_stage_2(str);
		}
		else if (**str == '/')
		{
			(*str)++;
			result /= eval_stage_2(str);
		}
		else if (**str == '%')
		{
			(*str)++;
			result %= eval_stage_2(str);
		}
	}
	return (result);
}

int	eval_stage_0(char **str)
{
	char	*s;
	int		result;

	result = eval_stage_1(str);
	s = *str;
	while (*s == '+' || *s == '-')
	{
		if (*s == '+')
		{
			s++;
			result += eval_stage_1(&s);
		}
		else if (*s == '-')
		{
			s++;
			result -= eval_stage_1(&s);
		}
	}
	*str = s;
	return (result);
}

int	eval_expr(char *str)
{
	char	*cleaned;
	char	*walker;
	int		result;

	cleaned = ft_ignore_whitespaces(str);
	walker = cleaned;
	result = eval_stage_0(&walker);
	free(cleaned);
	return (result);
}
