/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:25:08 by migferna          #+#    #+#             */
/*   Updated: 2019/12/12 18:56:13 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	check_flags(const char *format, t_printf *data)
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
	else
		return (0);
	format++;
	return (1);
}

//"%4d, 21"                             42
int	check_width(const char *format, t_printf *data)
{
	int number;

	number = 0;
	while (ft_isdigit(*format))
	{
		number *= 10;
		number = number + (*format - 48);
		format++;
	}
	data->width = number;
	return (number);
}
