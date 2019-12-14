/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:15:19 by migferna          #+#    #+#             */
/*   Updated: 2019/12/14 13:27:13 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(t_printf *data, void *p)
{
	/*if (data->minus_flag == 1)
		ft_putnbr_fd(number, 1);*/
	/*int len;
	int width;

	len = ft_strlen(ft_itoa(number));
	width = data->width - len;

	while (width-- > 0)
	{
		if (data->zero_flag == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (data->minus_flag == 0)
		ft_putnbr_fd(number, 1);*/

	printf("%p", p);

	return (0);

}
