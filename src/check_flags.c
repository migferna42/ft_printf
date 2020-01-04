/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:25:08 by migferna          #+#    #+#             */
/*   Updated: 2020/01/04 01:08:21 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*check_flags(t_printf *data)
{
	while (	data->format[data->it] == '0' ||
			data->format[data->it] == '+' ||
			data->format[data->it] == '-' ||
			data->format[data->it] == '*')
	{
	if (data->format[data->it] == '0' && data->it++)
		data->zero_flag = 1;
	else if (data->format[data->it] == '-' && data->it++)
		data->minus_flag = 1;
	else if (data->format[data->it] == '*' && data->it++)
		data->asterisk_flag = 1;
	else if (data->format[data->it] == '#' && data->it++)
		data->hast_flag = 1;
	else if (data->format[data->it] == '+' && data->it++)
		data->plus_flag = 1;
	}
	return (data);
}

t_printf	*check_width(t_printf *data)
{
	if (data->asterisk_flag == 1)
	{
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus_flag = 1;
			data->width *= -1;
		}
		return (data);
	}
	while (ft_isdigit(data->format[data->it]))
	{
		data->width *= 10;
		data->width += (data->treat[data->it] - 48);
		//printf("%d", data->it);
		if (data->it == (int)ft_strlen(data->format) - 1)
			break;
		data->it++;
	}

	return (data);
}

t_printf	*check_precision(t_printf *data)
{
	if (data->format[data->it] == '.')
	{
		data->it++;
		data->precision = 0;
		if (data->format[data->it] == '*')
		{
			data->precision = va_arg(data->args, int);
			data->it++;
			if (data->precision < 0)
				data->precision = -1;
			return (data);
		}
		while (ft_isdigit(data->format[data->it]))
		{
			data->precision *= 10;
			data->precision += (data->format[data->it] - 48);
			data->it++;
		}
	}
	return (data);
}
