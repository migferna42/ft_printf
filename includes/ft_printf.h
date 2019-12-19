/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:36:42 by migferna          #+#    #+#             */
/*   Updated: 2019/12/19 18:31:05 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_printf
{
	const char	*format;
	char		*copy;
	char		*treat;
	int			it;
	va_list		args;
	int			zero_flag;
	int			hast_flag;
	int			minus_flag;
	int			plus_flag;
	int			precision_flag;
	int			width;
	int			length;
	int			precision;
}				t_printf;

t_printf	*check_flags(t_printf *data);
t_printf	*check_width(t_printf *data);
t_printf	*check_precision(t_printf *data);
t_printf	*print_integer(t_printf *data);
t_printf	*print_string(t_printf *data);
t_printf	*print_char(t_printf *data);
void		ft_display(t_printf *data, char c, int width);

#endif
