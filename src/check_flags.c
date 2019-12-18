/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:25:08 by migferna          #+#    #+#             */
/*   Updated: 2019/12/16 12:58:31 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	check_flags(const char *format, int index, t_printf *data)
{
	format = format + index;
	if (*format == '0')
		data->zero_flag = 1;
	else if (*format == '-')
	{
		data->minus_flag = 1;
		data->zero_flag = 0;
	}
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
	return (1);
}

//"%-04d, 21"                             42
int	check_width(const char *format, int index, t_printf *data)
{
	int number;
	int pos;


	pos = 0;
	number = 0;
	format += index;
	while (ft_isdigit(*format))
	{
		number *= 10;
		number = number + (*format - 48);
		pos++;
		format++;
	}
	data->width = number;
	return (pos);
}

int	check_precision(const char *format, int index, t_printf *data)
{
	int number;
	int pos;

	pos = 0;
	number = 0;
	format += index;
	if (*format == '.')
	{
		data->zero_flag = 1;
		format++;
		pos++;
		while (ft_isdigit(*format))
		{
			number *= 10;
			number = number + (*format - 48);
			pos++;
			format++;
		}
		data->precision_flag = 1;
		data->precision = number;
	}
	return (pos);
}
