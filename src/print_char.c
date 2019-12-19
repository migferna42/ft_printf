/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:14:53 by migferna          #+#    #+#             */
/*   Updated: 2019/12/19 19:15:47 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

t_printf	*print_char(t_printf *data)
{
	/*int count;
	int width;

	width = data->width;
	count = 0;
	if (data->minus_flag == 1)
		ft_putchar_fd(c, 1);
	while (data->width != 0 && --width > 0)
	{
		if (data->zero_flag == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (data->minus_flag == 0)
		ft_putchar_fd(c, 1);
	return (0);*/
	//wint_t	c;

	char c;

	c = (char)va_arg(data->args, int);
	//c = (wint_t)c;
	if (data->zero_flag == 1 && data->minus_flag != 0)
		ft_display(data, '0', data->width - 1);
	else if(data->minus_flag == 0)
		ft_display(data, ' ', data->width - 1);
	write(1, &c, 1);
	if(data->minus_flag == 1)
		ft_display(data, ' ', data->width - 1);
	return (data);
}
