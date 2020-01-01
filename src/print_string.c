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

static char	*ft_calculate(t_printf *data, char *s)
{
	char	*cpy;

	if (data->precision > -1 && s)
	{
		cpy = ft_strdup("");
		ft_strlcpy(cpy, s, data->precision + 1);
		return (cpy);
	} 
	else if (data->precision == -1 && s)
		return (ft_strdup(s));
	else if (data->precision == -1 && !s)
		return (ft_strdup("(null)"));
	else if (data->precision > -1 && !s)
	{
		cpy = ft_strdup("(null)");
		s = cpy;
		ft_strlcpy(cpy, s, data->precision + 1);
		return (cpy);
	}
	return (s);
}

t_printf	*ft_print_string(t_printf *data)
{
	char	*s;
	int len;

	s = va_arg(data->args, char *);
	s = ft_calculate(data, s);
	len = ft_strlen(s);
	data->length += len;
	if (data->minus_flag == 0)
	{
		if (data->zero_flag == 1)
			ft_display(data, '0', data->width - len, 1);
		else
			ft_display(data, ' ', data->width - len, 1);
	}
	ft_putstr_fd(s, 1);
	if(data->minus_flag == 1)
		ft_display(data, ' ', data->width - len, 1);
	free(s);
	return (data);
}
