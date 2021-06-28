/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:53:50 by feschall          #+#    #+#             */
/*   Updated: 2021/06/25 01:14:21 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	n = i;
	while (src[i - n] && (i + 1) < dstsize)
	{
		dst[i] = src[i - n];
		i++;
	}
	if (n < dstsize)
		dst[i] = '\0';
	return (n + (ft_strlen(src)));
}
