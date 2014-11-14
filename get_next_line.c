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

t_index	ft_register_new_file(t_index index, const int fd)
{
	t_index		new_file;
	
	new_file = (t_index)malloc(sizeof(t_index));
	new_file->file[0] = fd;
	new_file->file[1] = 0;
	new_file->file[2] = 0;
	new_file->nxt = index;
	index->pvs = new_file;
	new_file->pvs = NULL;
	return (new_file);
}

int		ft_is_new_file(t_index index, const int fd)
{
	t_index		tmp;

	while (index->pvs != NULL)
		index = index->pvs;
	tmp = index;
	while (tmp != NULL)
	{
		if (tmp->file[0] == fd)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}

t_index ft_get_the_good_file(t_index index, const int fd)
{
	while (index->pvs != NULL)
		index = index->pvs;
	while (index->file[0] != fd)
		index = index->nxt;
	return (index);
}

int		get_next_line(const int fd, char **line)
{
	static t_index	index = NULL;

	if (ft_is_new_file(index, fd) == 1)
		index = ft_register_new_file(index, fd);
	




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
