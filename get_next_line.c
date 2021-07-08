/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:55:29 by tcharmel          #+#    #+#             */
/*   Updated: 2021/05/29 19:18:08 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (1);
		str++;
	}
	return (0);
}

static void	ft_del(char **s)
{
	free(*s);
	*s = NULL;
}

static int	ft_result(ssize_t ret, char **s, char **str)
{
	char	*tmp2;
	int		i;

	i = 0;
	if (ret < 0)
		return (-1);
	while ((*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s)[i] == '\n')
	{
		*str = ft_substr(*s, 0, i);
		tmp2 = ft_strdup(&((*s)[i + 1]));
		free (*s);
		*s = tmp2;
		if ((*s)[0] == '\0')
			ft_del(s);
	}
	else
	{
		*str = ft_strdup(*s);
		ft_del(s);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		ret;
	static char	*s = NULL;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(s, buff);
		free(s);
		s = tmp;
		if (ft_strchr(s, '\n') == 0)
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret == 0 && s == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_result(ret, &s, line));
}
