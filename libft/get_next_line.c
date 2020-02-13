/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:59:13 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/13 21:25:09 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_error(char **s, int fd)
{
	ft_strdel(&(s[fd]));
	return (-1);
}

int		ft_zap(const int fd, char **line, char **a)
{
	char	*str;
	int		i;

	i = 0;
	while (a[fd][i] != '\n' && a[fd][i] != '\0')
		i++;
	if (a[fd][i] == '\n')
	{
		if ((*line = ft_strsub(a[fd], 0, i)) == NULL)
			return (ft_error(&(a[fd]), fd));
		if ((str = ft_strdup(a[fd] + i + 1)) == NULL)
			return (ft_error(&(a[fd]), fd));
		free(a[fd]);
		a[fd] = str;
	}
	else
	{
		if ((*line = ft_strdup(a[fd])) == NULL)
			return (ft_error(&(a[fd]), fd));
		ft_strdel(&(a[fd]));
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*a[10240];
	char		*str;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE <= 0 || ((ret = read(fd, buf, 0)) < 0))
		return (-1);
	if (a[fd] == NULL)
		if ((a[fd] = ft_strnew(0)) == NULL)
			return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((str = ft_strjoinre(a[fd], buf, 1)) == NULL)
			return (ft_error(&(a[fd]), fd));
		a[fd] = str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (a[fd] == NULL || a[fd][0] == '\0'))
		return (0);
	return (ft_zap(fd, line, a));
}
