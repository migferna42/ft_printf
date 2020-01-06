/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:50:34 by migferna          #+#    #+#             */
/*   Updated: 2020/01/06 01:54:26 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int ft_numlen(long int number)
{
	int length;

	if (number < 0)
		number *= -1;
	length = 1;
	while ((number /= 10) > 0)
		length++;
	return (length);
}

static int	ft_isnegative(long int number)
{
	return (number < 0 ? 1 : 0);
}

static long int get_length(t_printf *data)
{
	long int num;

	if (ft_strcmp(data->length_flag, "hh") == 0)
		num = (signed char)(va_arg(data->args, int));
	else if (ft_strcmp(data->length_flag, "l") == 0)
		num = (long)(va_arg(data->args, long int));
	else if (ft_strcmp(data->length_flag, "h") == 0)
		num = (short)(va_arg(data->args, int));
	else if (ft_strcmp(data->length_flag, "ll") == 0)
		num = (long long)(va_arg(data->args, long long int));
	else
		num = va_arg(data->args, int);
	return (num);
}

static char	ft_sign(t_printf *data, int is_negative)
{
	if (is_negative)
		return ('-');
	if (data->plus_flag == 1)
		return ('+');
	if (data->space_flag == 1)
		return (' ');
	return ('\0');
}

t_printf	*ft_print_integer(t_printf *data)
{
	long int num;
	int length;
	int spaces;
	char sign;
	int is_negative;

	num = get_length(data);
	is_negative = (num < 0) ? 1 : 0;
	sign = ft_sign(data, is_negative);
	num *= (ft_isnegative(num) ? -1 : 1);
	length = ft_numlen(num);
	if (num == 0 && data->precision == 0)
	{
		ft_display(data, ' ', data->width, 1);
		return (data);
	}
	if (data->zero_flag == 1  && data->precision == -1 && data->minus_flag == 0)
	{
		data->precision = data->width;
		if (is_negative || data->plus_flag == 1)
			data->precision--;
	}
	spaces = length;
	if ( length <= data->precision && data->precision > -1 )
		spaces = data->precision;
	if (sign)
		spaces++;
	data->length += (data->width < spaces) ? spaces : data->width;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 0);
	if (sign)
		write(1, &sign, 1);
	ft_display(data, '0', data->precision - length, 0);
	ft_putnbrlong_fd(num, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces, 0);
	return (data);
}
