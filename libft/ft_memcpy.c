/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:57:38 by migferna          #+#    #+#             */
/*   Updated: 2019/11/09 10:50:07 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *pdst;
	unsigned char *psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (n == 0 || src == dst)
	{
		return (dst);
	}
	while (n-- > 0)
	{
		*(pdst++) = *(psrc++);
	}
	return (dst);
}
