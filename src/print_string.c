/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:39:40 by migferna          #+#    #+#             */
/*   Updated: 2019/12/13 16:08:50 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_string(t_printf *data, char *str)
{
	if (data->minus_flag == 1)
		ft_putstr_fd(str, 1);
	if (data->minus_flag == 0)
		ft_putstr_fd(str, 1);
	return (0);
}
