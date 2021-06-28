/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:11:22 by feschall          #+#    #+#             */
/*   Updated: 2020/11/26 21:25:54 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s2, const char *s1, size_t size)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (size == 0)
		return (ft_strlen(s1));
	while (s1[i] != '\0' && i < size - 1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (ft_strlen(s1));
}
