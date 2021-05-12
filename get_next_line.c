/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:00:59 by dpants            #+#    #+#             */
/*   Updated: 2021/05/11 21:00:59 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_line(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (NULL == new_line)
		return (NULL);
	new_line[i--] = '\0';
	while (i--)
		new_line[i] = str[i];
	free(str);
	return (new_line);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str;
	int			read_return;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_return = 1;
	if (!buf || !line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (read_return > 0 && !ft_strchr(str, '\n'))
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		buf[read_return] = '\0';
		str = ft_joinstr(str, buf);
	}
	free(buf);
	if (read_return == -1)
		return (-1);
	*line = ft_add_line(str);
	if (!read_return)
		return (0);
	return (1);
}
