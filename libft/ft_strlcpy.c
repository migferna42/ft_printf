/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:38:25 by migferna          #+#    #+#             */
/*   Updated: 2019/11/19 12:19:29 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		it;

	if (!dst)
		return (0);
	it = 0;
	len = ft_strlen(src);
	while (src[it] != '\0' && it < (int)(dstsize - 1))
	{
		dst[it] = src[it];
		it++;
	}
	if (dstsize)
		dst[it] = '\0';
	return (len);
}
