/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:09 by migferna          #+#    #+#             */
/*   Updated: 2019/12/10 19:18:24 by migferna         ###   ########.fr       */
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

//void	ft_conversion(va_list args)

int	ft_printf(const char *format, ...)
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
		{
			//handle_flags(format + 1, data);
			//handle_width();
			//handle_precision();
			//conversion(&++format);
			format++;
			if (*format == 'i')
			{
				print_integer(data->args);
			}
		}
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
	ft_printf("hola%i");
	return (0);
}
