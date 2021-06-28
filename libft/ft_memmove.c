/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:06:01 by feschall          #+#    #+#             */
/*   Updated: 2020/11/26 21:06:16 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			n;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (s2 == s1)
		return (s1);
	if (s2 < s1)
	{
		n = len;
		while (n-- > 0)
			s1[n] = s2[n];
	}
	else
	{
		n = 0;
		while (n < len)
		{
			s1[n] = s2[n];
			n++;
		}
	}
	return (s1);
}
