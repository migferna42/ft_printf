/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:09 by migferna          #+#    #+#             */
/*   Updated: 2019/12/16 13:13:10 by migferna         ###   ########.fr       */
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
}

void	handle_flags(const char *format, int index, t_printf *data)
{
	format += index;
	if (*format == 'c')
		print_char(data, (int)va_arg(data->args, int));
	else if (*format == 's')
		print_string(data, (char *)va_arg(data->args, char *));
	else if (*format == 'd' || *format == 'i')
		print_integer(data, (int)va_arg(data->args, int));
	/*else if (*format == 'p')
		print_pointer(data, (void *)va_arg(data->args, void *));
	else if (*format == 'u')
		print_unsigned_int(va_arg(args, unsigned int));
	else if ()*/
}

int		parse(const char *format, t_printf **data)
{
	int index;

	index = 0;
	ft_initialize(*data);
	index += check_flags(format, index, *data);
	index += check_width(format, index, *data);
	index += check_precision(format, index, *data);
	printf("%d", (*data)->width);
	handle_flags(format, index, *data);
	index = index + 1;
	return (index);
}

int		ft_printf(const char *format, ...)
{
	int count;
	int it;
	t_printf *data;

	if (!(data = malloc(sizeof(t_printf))))
		return (0);
	it = 0;
	count = 0;
	va_start(data->args, format);
	while (*format)
	{
		//count = 0;
		if (*format == '%')
		{
			format++;
			it = parse(format, &data);
			format += it;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			it++;
			format++;
		}
		count = count + it;
	}
	va_end(data->args);
	return (count);
}

int main(void)
{

	//printf("%d", printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',''));
	printf("%d", ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',''));
	return (0);
}
