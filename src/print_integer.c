/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:50:34 by migferna          #+#    #+#             */
/*   Updated: 2019/12/19 14:31:03 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*ft_print_integer(t_printf *data)
{
	/*if (data->minus_flag == 1)
		ft_putnbr_fd(number, 1);*/
	/*int len;
	int width;
	
	if (number < 0)
	{
		number *= -1;
		if (data->width == 0)
			ft_putchar_fd('-', 1);
	}
	len = ft_strlen(ft_itoa(number));
	width = (data->width + data->precision ) - len;
	if (data->minus_flag == 1)
		ft_putnbr_fd(number, 1);
	while (width-- > 0)
	{
		if (data->zero_flag == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (data->minus_flag == 0)
		ft_putnbr_fd(number, 1);*/
	return (data);
}
