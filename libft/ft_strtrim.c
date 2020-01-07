/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:22:03 by migferna          #+#    #+#             */
/*   Updated: 2019/11/19 07:59:17 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *s)
{
	int len;
	int it;

	it = 0;
	len = ft_strlen(s);
	while (it < len)
	{
		if (s[it] == c)
			return (1);
		it++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	k;
	size_t	len;
	size_t	i;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	k = 0;
	len = ft_strlen(s1);
	while (ft_inset(s1[i], set))
		i++;
	while (len > 0 && ft_inset(s1[len - 1], set))
		len--;
	if (len < i)
		len = i;
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[k++] = s1[i++];
	}
	str[k] = '\0';
	return (str);
}
