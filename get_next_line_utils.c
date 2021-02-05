/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:18:10 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/12 11:18:18 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
	return ;
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (str == (char*)s)
	{
		str[j] = '\0';
		return (str);
	}
	if ((int)start > ft_strlen(s))
	{
		str[j] = '\0';
		return (str);
	}
	while (j < len)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*p;
	int		size;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	if (!(p = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		else
			str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	if (s1)
	{
		while (*s1)
			str[i++] = *s1++;
	}
	if (s2)
	{
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (0);
}
