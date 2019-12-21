/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:50:34 by migferna          #+#    #+#             */
/*   Updated: 2019/12/21 16:36:49 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*ft_print_integer(t_printf *data)
{
	int num;
	int length;
	int spaces;

	num = va_arg(data->args, int);
	length = ft_strlen(ft_itoa(num));
	spaces = length;
	if ( length <= data->precision && data->precision > -1 )
		spaces = data->precision;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces);
	ft_display(data, '0', data->precision - data->width);
	ft_putnbr_fd(num, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces);
	return (data);
}
