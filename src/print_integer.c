/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:50:34 by migferna          #+#    #+#             */
/*   Updated: 2019/12/10 19:19:51 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list ap)
{
	printf("eeeeee");
	int value;

	value = va_arg(ap, int);
	printf("%d", value);
	return (0);
}
