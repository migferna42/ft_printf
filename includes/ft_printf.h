/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:36:42 by migferna          #+#    #+#             */
/*   Updated: 2019/12/12 18:56:33 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_printf
{
	va_list		args;
	int			zero_flag;
	int			hast_flag;
	int			minus_flag;
	int			plus_flag;
	int			width;
}				t_printf;

int	check_flags(const char *format, t_printf *data);
int	check_width(const char *format, t_printf *data);
int	print_integer(t_printf *data, int number);
int	print_string(t_printf *data, const char *str);
int	print_char(t_printf *data, char c);

#endif
