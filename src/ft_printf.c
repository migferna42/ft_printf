/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:09 by migferna          #+#    #+#             */
/*   Updated: 2019/12/12 17:46:42 by migferna         ###   ########.fr       */
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

void	handle_flags(const char *format, t_printf *data)
{
	if (*format == 'c')
		print_char(data, (int)va_arg(data->args, int));
	else if (*format == 's')
		print_string(data, (char *)va_arg(data->args, char *));
	else if (*format == 'd' || *format == 'i')
		print_integer(data, (int)va_arg(data->args, int));
	/*else if (*format == 'u')
		print_unsigned_int(va_arg(args, unsigned int));
	else if ()*/
}

int		parse(const char *format, t_printf *data)
{
	int cont;

	cont = 0;
	printf("\n%s", format++);
	cont += check_flags(format, data);
	printf("\n%s", format);
	cont += check_width(format, data);
	printf("\n%s", format);
	//cont += check_precision();
	handle_flags(format, data);
	return (cont);
}

int		ft_printf(const char *format, ...)
{
	int count;
	t_printf *data;

	if (!(data = malloc(sizeof(t_printf))))
		return (0);
	ft_initialize(data);
	count = 0;
	va_start(data->args, format);
	while (*format)
	{
		if (*format == '%')
			count += parse(++format, data);
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(data->args);
	return (count);
}

int main(void)
{
	//printf("%01000d",  1234);
	ft_printf("hola%-231c", 'd');
	return (0);
}
