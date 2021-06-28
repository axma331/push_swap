/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:19:26 by feschall          #+#    #+#             */
/*   Updated: 2020/11/26 21:28:31 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bstr, const char *lstr, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (ft_strlen((char *)lstr) == 0)
		return ((char *)bstr);
	while (bstr[b])
	{
		l = 0;
		while (lstr[l] && b + l < len && lstr[l] == bstr[b + l])
			l++;
		if (lstr[l] == '\0')
			return ((char *)bstr + b);
		b++;
	}
	return (0);
}
