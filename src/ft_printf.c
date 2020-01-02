/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:09 by migferna          #+#    #+#             */
/*   Updated: 2020/01/02 20:33:18 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_initialize(t_printf *data)
{
	data->zero_flag = 0;
	data->hast_flag = 0;
	data->plus_flag = 0;
	data->minus_flag = 0;
	data->width = 0;
	data->length = 0;
	data->precision_flag = 0;
	//data->precision = -1;
	data->it = 0;
	data->copy = (char *)data->format;
	data->treat = (char *)data->format;
}

void	ft_clear(t_printf *data)
{
	data->width = 0;
	data->precision = -1;
}

void	handle_flags(t_printf *data)
{
	/*format += index;*/
	if (data->format[data->it] == 'c')
		ft_print_char(data);
	else if (data->format[data->it] == 's')
		ft_print_string(data);
	else if (data->format[data->it] == 'd' || data->format[data->it] == 'i')
		ft_print_integer(data);
	else if (data->format[data->it] == 'u')
		ft_print_unsigned(data);
	else if (data->format[data->it] == 'p')
		ft_print_pointer(data);
	else if (data->format[data->it] == 'x')
		ft_print_hexadecimal(data, 'x');
	else if (data->format[data->it] == 'X')
		ft_print_hexadecimal(data, 'X');
	else if (data->format[data->it] == '%')
		ft_print_percent(data);
}

int		procesate(t_printf *data)
{
	data->it++;
	check_flags(data);
	check_width(data);
	check_precision(data);
	handle_flags(data);
	return (data->length);
}

int		parse(t_printf *data)
{
	while (data->copy[data->it] != '\0')
	{
		if (data->copy[data->it] == '%')
		{
			ft_clear(data);
			procesate(data);
		}
		else
		{
			ft_putchar_fd(data->copy[data->it], 1);
			data->length++;
		}
		data->it++;
	}
	return (data->length);
}

int		ft_printf(const char *format, ...)
{
	t_printf *data;

	if (!(data = malloc(sizeof(t_printf))))
		return (0);
	data->format = format;
	ft_initialize(data);
	if (format)
	{
		va_start(data->args, format);
		data->length = parse(data);
		va_end(data->args);
	}
	free(data);
	return (data->length);
}

/*int main(void)
{
	char a;
	//printf("%.03s", NULL);
	ft_printf("%p", &a);

	return (0);
}*/
