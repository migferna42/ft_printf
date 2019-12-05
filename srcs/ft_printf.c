/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:09 by migferna          #+#    #+#             */
/*   Updated: 2019/12/05 18:28:29 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int count;
	t_printf data;

	if (!(data = malloc(sizeof(t_printf))))
		return (NULL);
	count = 0;
	va_start(data.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
		}
		else
		{
			//ft_putchar_fd(*format, 1);
			write(1, &format, 1);
			count++;
		}
		format++;
	}
	va_end(data.args);
	return (count);
}

int main(void)
{
	ft_printf("hola");
	return (0);
}
