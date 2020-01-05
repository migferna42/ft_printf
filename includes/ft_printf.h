/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:36:42 by migferna          #+#    #+#             */
/*   Updated: 2020/01/05 19:48:51 by migferna         ###   ########.fr       */
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
	int			space_flag;
	int			asterisk_flag;
	int			precision_flag;
	int			width;
	char		length_flag[2];
	int			length;
	int			precision;
}				t_printf;

t_printf	*check_flags(t_printf *data);
t_printf	*check_width(t_printf *data);
t_printf	*check_length(t_printf *data);
t_printf	*check_precision(t_printf *data);
t_printf	*ft_print_integer(t_printf *data);
t_printf	*ft_print_string(t_printf *data);
t_printf	*ft_print_char(t_printf *data);
t_printf	*ft_print_unsigned(t_printf *data);
t_printf	*ft_print_pointer(t_printf *data);
t_printf	*ft_print_hexadecimal(t_printf *data, char c);
t_printf	*ft_print_percent(t_printf *data);
void		ft_display(t_printf *data, char c, int width, int update);

#endif
