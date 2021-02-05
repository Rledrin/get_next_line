/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:18:25 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/12 11:18:59 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(int size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

void	ft_swapfree(char **gnl, char *tmp, int fd)
{
	free(gnl[fd]);
	gnl[fd] = tmp;
}

int		ft_new_line(char **gnl, char **line, int fd, ssize_t ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (gnl[fd][len] != '\n' && gnl[fd][len] != '\0')
		len++;
	if (gnl[fd][len] == '\n')
	{
		*line = ft_substr(gnl[fd], 0, len);
		tmp = ft_strdup(gnl[fd] + len + 1);
		ft_swapfree(gnl, tmp, fd);
		if (gnl[fd][0] == '\0')
			ft_strdel(&gnl[fd]);
	}
	else if (gnl[fd][len] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(gnl[fd]);
		ft_strdel(&gnl[fd]);
		if (*line == NULL)
			*line = ft_strnew(0);
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*gnl[255];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		ret;
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (gnl[fd] == NULL)
			gnl[fd] = ft_strnew(0);
		tmp = ft_strjoin(gnl[fd], buf);
		ft_swapfree(gnl, tmp, fd);
		if ((ft_strchr(buf, '\n')) || (ft_strchr(buf, '\0')))
			break ;
		return (1);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (gnl[fd] == NULL || gnl[fd][0] == '\0'))
		*line = ft_strnew(0);
	if (ret == 0 && (gnl[fd] == NULL || gnl[fd][0] == '\0'))
		return (0);
	return (ft_new_line(gnl, line, fd, ret));
}
