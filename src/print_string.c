/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:39:40 by migferna          #+#    #+#             */
/*   Updated: 2019/12/14 16:04:58 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_string(t_printf *data, char *str)
{
	int len;
	char *cpy;

	if (!str)
		return (0);
	if (data->precision != 0)
	{
		cpy = ft_strdup("");
		ft_strlcpy(cpy, str, data->precision + 1);
		str = cpy;
	}
	len = data->width - ft_strlen(str);
	if (data->minus_flag == 1)
		ft_putstr_fd(str, 1);
	while (len-- > 0)
	{
		if (data->zero_flag == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (data->minus_flag == 0)
		ft_putstr_fd(str, 1);
	return (0);
}
