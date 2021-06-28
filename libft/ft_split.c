/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:40:56 by feschall          #+#    #+#             */
/*   Updated: 2021/06/25 19:33:19 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	count(char const *s, char c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			l++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (l);
}

static char	**freelloc(char **s, int i)
{
	while (i != 0)
	{
		free(s[i]);
		i--;
	}
	free(s[i]);
	return (0);
}

static	char	**for_split(char const *s, char c, char	**arr, int i)
{
	int	j;
	int	m;

	j = 0;
	m = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i])
	{
		arr[m] = (char *)malloc(sizeof(char) * (len(s + i, c) + 1));
		if (!arr[m])
			return (freelloc(arr, m));
		while (s[i] && s[i] != c)
			arr[m][j++] = s[i++];
		arr[m++][j] = 0;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		m;

	i = 0;
	m = 0;
	arr = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!s || !arr)
		return (0);
	while (s[i])
		for_split(s, c, arr, i);
	arr[m] = 0;
	return (arr);
}
