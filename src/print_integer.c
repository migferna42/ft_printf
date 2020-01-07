/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:50:34 by migferna          #+#    #+#             */
/*   Updated: 2020/01/07 18:52:27 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int		ft_numlen(long int number)
{
	int length;

	if (number < 0)
		number *= -1;
	length = 1;
	while ((number /= 10) > 0)
		length++;
	return (length);
}

static long int	get_length(t_printf *data)
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

static char		ft_sign(t_printf *data, int is_negative)
{
	if (is_negative)
		return ('-');
	if (data->plus_flag == 1)
		return ('+');
	if (data->space_flag == 1)
		return (' ');
	return ('\0');
}

static t_printf	*print(t_printf *data, long int num, int nbrlen)
{
	int			spaces;
	int			is_negative;
	int			sign;

	is_negative = (num < 0) ? 1 : 0;
	num *= ((is_negative) ? -1 : 1);
	sign = ft_sign(data, is_negative);
	spaces = nbrlen;
	if (nbrlen <= data->precision && data->precision > -1)
		spaces = data->precision;
	if (sign)
		spaces++;
	data->length += (data->width < spaces) ? spaces : data->width;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 0);
	if (sign)
		write(1, &sign, 1);
	ft_display(data, '0', data->precision - nbrlen, 0);
	ft_putnbrlong_fd(num, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces, 0);
	return (data);
}

t_printf		*ft_print_integer(t_printf *data)
{
	long int	num;
	int			length;

	num = get_length(data);
	length = ft_numlen(num);
	if (num == 0 && data->precision == 0)
	{
		ft_display(data, ' ', data->width, 1);
		return (data);
	}
	if (data->zero_flag == 1 && data->precision == -1 && data->minus_flag == 0)
	{
		data->precision = data->width;
		if (num < 0 || data->plus_flag == 1)
			data->precision--;
	}
	print(data, num, length);
	return (data);
}
