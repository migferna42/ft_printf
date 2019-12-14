/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:50:34 by migferna          #+#    #+#             */
/*   Updated: 2019/12/14 11:08:22 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_integer(t_printf *data, int number)
{
	/*if (data->minus_flag == 1)
		ft_putnbr_fd(number, 1);*/
	int len;
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
		ft_putnbr_fd(number, 1);

	return (0);

}
