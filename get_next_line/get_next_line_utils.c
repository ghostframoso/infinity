/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:55:16 by jomason           #+#    #+#             */
/*   Updated: 2026/02/06 10:59:18 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*united;
	size_t	j;
	size_t	i;
	size_t	m;

	i = 0;
	j = 0;
	m = (ft_strlen(s1) + ft_strlen(s2));
	united = (char *)malloc(sizeof(char) * m + 1);
	if (!united)
		return (NULL);
	while (s1[i])
	{
		united[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		united[i] = s2[j];
		i++;
		j++;
	}
	united[i] = '\0';
	return (united);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	i = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (dstsize == 0)
		return (len_src);
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
