/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:26:39 by feschall          #+#    #+#             */
/*   Updated: 2021/06/25 19:36:06 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	s2 = ((char *)malloc(sizeof(char) * (len + 1)));
	if (!s2)
		return (0);
	while (i <= len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
