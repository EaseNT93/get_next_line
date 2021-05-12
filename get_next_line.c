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
		str = /* add the contents of the buffer to the string */;
	}
	free(buf);
	if (read_return == -1)
		return (-1);
	*line = /* add str into line */;
	if (!read_return)
		return (0);
	return (1);
}
