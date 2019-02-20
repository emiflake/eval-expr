/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:57:52 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/20 23:38:53 by emiflake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>
/*#define DEBUG*/

int	eval_stage_2(char **str)
{
	int result;

	result = 0;
#ifdef DEBUG
	printf("=> Stage 2: '%s' -> #(%d)\n", *str, result);
#endif
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
#ifdef DEBUG
	printf("=> Stage 1: '%s' -> #(%d)\n", *str, result);
#endif
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
	char *s;
	int result;

	result = eval_stage_1(str);
#ifdef DEBUG
	printf("=> Stage 0: '%s' -> #(%d)\n", *str, result);
#endif
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
	char *cleaned;
	char *walker;
	int result;

	cleaned = ft_ignore_whitespaces(str);
	walker = cleaned;
#ifdef DEBUG
	printf("===> Cleaned : '%s' \n", cleaned);
#endif
	result = eval_stage_0(&walker);
	free(cleaned);
	return (result);
}
