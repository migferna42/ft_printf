/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:15:19 by migferna          #+#    #+#             */
/*   Updated: 2019/12/14 13:27:13 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_length_number(int number, int base)
{
	int lenght;

	lenght = 1;
	while ((number /= base) > 0)
		lenght++;
	return (lenght);
}

static char	*ft_itoa_base(int number, int base)
{
	char	*str;
	int		length;
	char	*base_string = "0123456789abcdef";

	if (number == 0)
		return (ft_strdup("0"));
	length = ft_length_number(number, 16);
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	str[length--] = '\0';
	while (number)
	{
		str[length--] = base_string[number % base];
		number /= base;
	}
	return (str);
}


t_printf *ft_print_pointer(t_printf *data)
{
	unsigned int	num;
	char			*str;
	int				spaces;

	num = va_arg(data->args, unsigned int);
	str = ft_itoa_base(num, 16);
	if (!str)
		return (NULL);
	if (num == 0 && data->precision == 0)
		*str = '\0';
	if (data->zero_flag == 1 && data->precision == 1)
	{
		data->precision = data->width - 2;
		data->width = 0;
	}
	spaces = ft_strlen(str) + 2;
	data->length += (data->width < spaces) ? spaces : data->width;
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - spaces, 1);
	ft_putstr_fd("0x", 1);
	ft_display(data, '0', (data->precision - spaces) + 2, 1);
	ft_putstr_fd(str, 1);
	return (data);
}
