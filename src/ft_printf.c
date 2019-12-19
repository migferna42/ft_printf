/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:09 by migferna          #+#    #+#             */
/*   Updated: 2019/12/19 19:17:26 by migferna         ###   ########.fr       */
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
	data->precision_flag = 0;
	data->precision = 0;
	data->it = 0;
	data->copy = (char *)data->format;
	data->treat = (char *)data->format;
}

void	ft_clear(t_printf *data)
{
	data->width = 0;
	data->precision = 0;
}

void	handle_flags(t_printf *data)
{
	/*format += index;*/
	if (data->format[data->it] == 'c')
		print_char(data);
	else if (data->format[data->it] == 's')
		print_string(data);
	//else if (*format == 'd' || *format == 'i')
	//	print_integer(data, (int)va_arg(data->args, int));

	/*else if (*format == 'p')
		print_pointer(data, (void *)va_arg(data->args, void *));
	else if (*format == 'u')
		print_unsigned_int(va_arg(args, unsigned int));
	else if ()*/
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

int main(void)
{
	//printf("%d", printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',''));
	ft_printf("%c",'x');
	//printf("%d", printf("%1c%2c",'a', 'b'));
	return (0);
}
