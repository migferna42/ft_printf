/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:56:40 by migferna          #+#    #+#             */
/*   Updated: 2019/12/20 09:03:26 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_display(t_printf *data, char c, int width)
{
	if (width > 0)
	{
		data->length += width;
		while (width-- > 0)
			write(1, &c, 1);
	}
}
