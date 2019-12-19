/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:39:40 by migferna          #+#    #+#             */
/*   Updated: 2019/12/19 14:32:53 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*ft_print_string(t_printf *data)
{
	/*int len;
	char *cpy;

	if (!str)
		str = ft_strdup("(null)");
	if (data->precision != 0)
	{
		cpy = ft_strdup("");
		ft_strlcpy(cpy, str, data->precision + 1);
		str = cpy;
	}
	if (data->precision_flag == 1 && data->precision == 0)
	{
		str = ft_strdup("");
	}
	len = data->width - ft_strlen(str);
	if (data->minus_flag == 1 &&
		!(data->precision_flag == 1 && data->precision == 0
))
		ft_putstr_fd(str, 1);
	while (len-- > 0)
	{
		if (data->zero_flag == 1)
			ft_putchar_fd('0', 1);
		//else
			ft_putchar_fd(' ', 1);
	}
	if (data->minus_flag == 0 &&
		!(data->precision_flag == 1 && data->precision == 0
))
		ft_putstr_fd(str, 1);*/
	return (data);
}
