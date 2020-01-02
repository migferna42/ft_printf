/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:14:53 by migferna          #+#    #+#             */
/*   Updated: 2020/01/02 17:41:44 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*ft_print_char(t_printf *data)
{
	char c;

	c = (char)va_arg(data->args, int);
	if (data->minus_flag == 0)
	{
		if (data->zero_flag == 1)
			ft_display(data, '0', data->width - 1, 1);
		else
			ft_display(data, ' ', data->width - 1, 1);
	}
	write(1, &c, 1);
	data->length++;
	if(data->minus_flag == 1)
		ft_display(data, ' ', data->width - 1, 1);
	return (data);
}
