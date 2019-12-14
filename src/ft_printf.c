/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:09 by migferna          #+#    #+#             */
/*   Updated: 2019/12/14 19:12:40 by migferna         ###   ########.fr       */
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
}

void	handle_flags(const char *format, int index, t_printf *data)
{
	format += index;
	if (*format == 'c')
		print_char(data, (int)va_arg(data->args, int));
	else if (*format == 's')
		print_string(data, (char *)va_arg(data->args, char *));
	/*else if (*format == 'd' || *format == 'i')
		print_integer(data, (int)va_arg(data->args, int));
	else if (*format == 'p')
		print_pointer(data, (void *)va_arg(data->args, void *));
	else if (*format == 'u')
		print_unsigned_int(va_arg(args, unsigned int));
	else if ()*/
}

int		parse(const char *format, t_printf *data)
{
	int index;

	index = 0;
	ft_initialize(data);
	index += check_flags(format, index, data);
	index += check_width(format, index, data);
	index += check_precision(format, index, data);
	handle_flags(format, index, data);

	return (index);
}

int		ft_printf(const char *format, ...)
{
	int count;
	t_printf *data;

	if (!(data = malloc(sizeof(t_printf))))
		return (0);
	count = 0;
	va_start(data->args, format);
	while (*format)
	{
		count = 0;
		if (*format == '%')
		{
			count = parse(++format, data);
			format += (count + 1);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
			format++;
		}
	}
	va_end(data->args);
	return (count);
}

/*int main(void)
{
	void *a;

	a = 0;
	printf("hello, %s.\n", "gavin");
	ft_printf("hello, %s.", "gavin");
	return (0);
}*/
