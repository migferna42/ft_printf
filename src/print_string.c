/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:39:40 by migferna          #+#    #+#             */
/*   Updated: 2019/12/20 12:37:48 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_printf	*ft_print_string(t_printf *data)
{
	char	*s;
	char	*cpy;
	int len;

	s = va_arg(data->args, char *);
	if (data->precision > -1 && s)
	{
		cpy = ft_strdup("");
		ft_strlcpy(cpy, s, data->precision + 1);
		s = cpy;
	}
	else if (data->precision == -1 && s)
		s = ft_strdup(s);
	else if (!s && data->precision == -1)
		s = ft_strdup("(null)");
	else if (!s && data->precision > -1)
	{
		cpy = ft_strdup("(null)");
		s = cpy;
		ft_strlcpy(cpy, s, data->precision + 1);
		s = cpy;
	}
	len = ft_strlen(s);
	data->length += len;
	if (data->zero_flag == 1 && data->minus_flag == 0)
		ft_display(data, '0', data->width - len);
	else if(data->minus_flag == 0)
		ft_display(data, ' ', data->width - len);
	ft_putstr_fd(s, 1);
	if(data->minus_flag == 1)
		ft_display(data, ' ', data->width - len);
	//free(s);
	return (data);
}
