/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:35:03 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/13 16:32:58 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE];
	static int	noline = 0;
	int			i;
	int			isfinish;

	i = 1;
	isfinish = 1;
	if ((int)read(fd, buffer[0], 1) == -1)
		return (-1);
	while (buffer[i - 1] != '\n' && isfinish > 0)
		isfinish = read(fd, buffer[i++], 1);
	if (isfinish = -1)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		line[noline][i] = buffer[i];
		i++;
	}
	if (isfinish > 0)
	{
		noline++;
		return (1);
	}
	return (0);
}
