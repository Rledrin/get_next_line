/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:18:32 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/12 11:18:54 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_strdel(char **as);
char	*ft_substr(char *s, unsigned int start, int len);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_new_line(char **gnl, char **line, int fd, ssize_t ret);
int		get_next_line(int fd, char **line);
char	*ft_strnew(int size);
void	ft_swapfree(char **gnl, char *tmp, int fd);

#endif
