/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 18:19:12 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/20 18:26:31 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <stdlib.h>

int		ft_isspace(char c);
int		ft_atoi(char *str);
char	*ft_ignore_whitespaces(char *str);
int		ft_strlen(char *str);
int		eval_expr(char *str);

#endif
