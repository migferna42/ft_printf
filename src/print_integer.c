/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:50:34 by migferna          #+#    #+#             */
/*   Updated: 2020/01/04 00:47:21 by migferna         ###   ########.fr       */
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

t_printf	*ft_print_integer(t_printf *data)
{
	long int num;
	int length;
	int spaces;

	num = va_arg(data->args, int);
	length = ft_numlen(num);
	if (num == 0 && data->precision == 0)
	{
		ft_display(data, ' ', data->width, 1);
		return (data);
	}
	if (data->zero_flag == 1  && data->precision == -1 && data->minus_flag == 0)
	{
		data->precision = data->width;
		if (num < 0)
			data->precision--;
	}
	spaces = length;
	if ( length <= data->precision && data->precision > -1 )
		spaces = data->precision;
	if (ft_isnegative(num))
		spaces++;
	data->length += (data->width < spaces) ? spaces : data->width;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 0);
	if (ft_isnegative(num))
	{
		num *= -1;
		write(1, "-", 1);
	}
	ft_display(data, '0', data->precision - length, 0);
	ft_putnbr_fd(num, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces, 0);
	return (data);
}
