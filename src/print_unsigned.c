/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:06:40 by migferna          #+#    #+#             */
/*   Updated: 2019/12/20 17:07:48 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		ft_get_length(unsigned int number)
{
	int length;

	length = 0;
	if (number < 0)
		number *= -1;
	while ((number /= 10) > 0)
		length++;
	return (length);
}

t_printf		*ft_print_unsigned(t_printf *data)
{
	unsigned int num;
	int length;

	num = va_arg(data->args, unsigned int);
	length = ft_get_length(num);
	if (length <= data->precision)
		length = data->precision;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - length - 1);
	ft_display(data, '0', data->precision - data->width);
	ft_putnbr_fd(num, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - length - 1);
	return (data);
}
