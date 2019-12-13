/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:14:53 by migferna          #+#    #+#             */
/*   Updated: 2019/12/13 16:04:19 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	print_char(t_printf *data, char c)
{
	if (data->minus_flag == 1)
		ft_putchar_fd(c, 1);
	while (--data->width > 0)
	{
		if (data->zero_flag == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (data->minus_flag == 0)
		ft_putchar_fd(c, 1);
	return (0);
}
