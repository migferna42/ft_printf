/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:39:35 by migferna          #+#    #+#             */
/*   Updated: 2020/01/02 20:30:22 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_nbrlen(unsigned int number, int base)
{
	int length;
	(void) base;
	(void) number;

	length = 1;
	while ((number /= base) > 0)
		length++;
	return (length);
}

static char	*ft_itoa_base(unsigned int number, int base)
{
	char *str;
	int length;
	char	*base_string = "0123456789abcdef";

	if (number == 0)
		return (ft_strdup("0"));
	length = ft_nbrlen(number, base);
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	str[length] = '\0';
	while (number)
	{
		str[--length] = base_string[number % base];
		number /= base;
	}
	return (str);
}

t_printf *ft_print_hexadecimal(t_printf *data)
{
	char	*str;
	unsigned long num;
	int width;
	int spaces;

	num = va_arg(data->args, unsigned long);
	if (data->zero_flag == 1 && data->precision == -1)
	{
		data->precision = data->width;
		data->width = 0;
	}
	if (num == 0 && data->precision == 0)
	{
		ft_display(data, ' ', data->width, 1);
		return (data);
	}
	str = ft_itoa_base(num, 16);
	width = ft_strlen(str);
	spaces = (data->precision > 0 && data->precision >= width) ? data->precision : width;
	data->length += (data->width < spaces) ? spaces : data->width;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 0);
	ft_display(data, '0', data->precision - width, 0);
	ft_putstr_fd(str, 1);
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - spaces, 0);
	free(str);
	return (data);
}
