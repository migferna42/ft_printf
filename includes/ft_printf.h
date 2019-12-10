/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:36:42 by migferna          #+#    #+#             */
/*   Updated: 2019/12/10 18:41:56 by migferna         ###   ########.fr       */
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
}				t_printf;

int	print_integer();
int	print_string();

#endif
