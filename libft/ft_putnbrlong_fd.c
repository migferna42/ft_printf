/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlong_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:34:39 by migferna          #+#    #+#             */
/*   Updated: 2020/01/07 19:36:28 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrmax_fd(long int number, int fd)
{
	if (number == -9223372036854775807 - 1)
		write(1, "-9223372036854775808", 20);
	else
	{
		if (number < 0)
		{
			ft_putchar_fd('-', fd);
			number *= -1;
		}
		if (number > 9)
			ft_putnbrmax_fd(number / 10, fd);
		ft_putchar_fd((number % 10) + '0', fd);
	}
}
