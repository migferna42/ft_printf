/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:25:08 by migferna          #+#    #+#             */
/*   Updated: 2019/12/10 16:24:15 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flags(char *format, t_printf *data)
{
	while (	*format == '0' ||
			*format == '-' ||
			*format == '.' ||
			*format == '*')
	{
		if (*format == '0')
			data->zero_flag = 1;
		else if (*format == '-')
			data->minus_flag = 1;
		/*else if (*format == '.')
			data->flags[2] = 1;
		else if (*format == '*')
			return ;*/
		else if (*format == '#')
			data->hast_flag = 1;
		else if (*format == '+')
			data->plus_flag = 1;
		format++;
	}
}
