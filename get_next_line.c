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

t_file	ft_register_new_file(t_file index, const int fd)
{
	t_file		new_file;

	
	return (new_file);
}

int		ft_is_new_file(t_file index, const int fd)
{
	t_file		*tmp;

	tmp = index;
	while (tmp != NULL)
	{
		if (tmp->file[0] == fd)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
/* version with chain list */
{
	static t_file	index = NULL;

	if (ft_is_new_file(index, fd) == 1)





}





/*
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
*/
