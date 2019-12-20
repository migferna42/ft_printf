/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:39:40 by migferna          #+#    #+#             */
/*   Updated: 2019/12/20 11:59:38 by migferna         ###   ########.fr       */
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
	else if (data->precision == 1 && s)
		s = ft_strdup(s);
	else if (!s && data->precision == -1)
		s = ft_strdup("(null)");
	else if (!s && data->precision > -1)
	{
		cpy = ft_strdup("");
		ft_strlcpy(cpy, s, data->precision + 1);
		s = cpy;
	}
	/*else if (s && data->precision < 0)
		s = ft_strdup(s);
	else if (s && data->precision > -1)
	{
		cpy = ft_strdup("");
		ft_strlcpy(cpy, s, data->precision);
		s = cpy;
	}*/
		
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
