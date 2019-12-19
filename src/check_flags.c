/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:25:08 by migferna          #+#    #+#             */
/*   Updated: 2019/12/19 18:38:12 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*check_flags(t_printf *data)
{
	if (data->format[data->it] == '0')
		data->zero_flag = 1;
	else if (data->format[data->it] == '-')
	{
		data->minus_flag = 1;
		//data->zero_flag = 0;
	}
	/*else if (*format == '.')
		data->flags[2] = 1;
	else if (*format == '*')
		return ;*/
	else if (data->format[data->it] == '#')
		data->hast_flag = 1;
	else if (data->format[data->it] == '+')
		data->plus_flag = 1;
	return (data);
}

t_printf	*check_width(t_printf *data)
{
	while (ft_isdigit(data->format[data->it]))
	{
		data->width *= 10;
		data->width += (data->treat[data->it] - 48);
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
		while (ft_isdigit(data->format[data->it]))
		{
			data->precision *= 10;
			data->precision += (data->format[data->it] - 48);
			data->it++;
		}
	}
	return (data);
}
