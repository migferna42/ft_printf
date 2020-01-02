/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:06:40 by migferna          #+#    #+#             */
/*   Updated: 2020/01/02 17:42:04 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		ft_get_length(unsigned int number)
{
	int length;

	if (number < 0)
		number *= -1;
	length = 1;
	while ((number /= 10) > 0)
		length++;
	return (length);
}

void	ft_putnbruint(unsigned int number, int fd)
{
	if (number > 9)
		ft_putnbruint(number / 10, fd);
	ft_putchar_fd((number % 10) + '0', fd);
}

t_printf		*ft_print_unsigned(t_printf *data)
{
	unsigned int num;
	int length;
	int spaces;

	num = (unsigned int)va_arg(data->args, unsigned int);
	length = ft_get_length(num);
	if (num == 0 && data->precision == 0)
	{
		ft_display(data, ' ', data->width, 1);
		return (data);
	}
	if (data->zero_flag == 1 && data->precision == -1)
		data->precision = data->width;
	spaces = length;
	if (spaces <= data->precision)
		spaces = data->precision;
	data->length += (data->width < spaces) ? spaces : data->width;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 0);
	ft_display(data, '0', data->precision - length, 0);
	ft_putnbruint(num, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces, 0);
	return (data);
}
