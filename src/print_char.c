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

t_printf	*ft_print_char(t_printf *data)
{
	char c;
	c = (char)va_arg(data->args, int);
	//c = (wint_t)c;
	if (data->zero_flag == 1 && data->minus_flag == 0)
		ft_display(data, '0', data->width - 1);
	else if(data->minus_flag == 0)
		ft_display(data, ' ', data->width - 1);
	write(1, &c, 1);
	if(data->minus_flag == 1)
		ft_display(data, ' ', data->width - 1);
	return (data);
}
