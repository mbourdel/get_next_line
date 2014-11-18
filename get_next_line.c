/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:35:03 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/18 17:31:27 by mbourdel         ###   ########.fr       */
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
	char		c;

	if (read(fd, &c, 1) == -1)
		return (-1);
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

char	*ft_get_this_line(t_index index, char buff[BUFF_SIZE])
{
	int		i;
	int		error;
	int		charead;

	i = 0;
	error = 1;
	charead = index->file[2];
	while (buff[i - 1] != '\n' && buff[i- 1] && error == 1)
		error = read(fd, buff[i++], 1);
	index->file[1] += 1;
	index->file[2] += i;
	return (buff);
}

int		get_next_line(const int fd, char **line)
{
	static 	t_index	index = NULL;
	int		error;
	char	buff[BUFF_SIZE];

	error = 0;
	if ((error = ft_is_new_file(index, fd)) == 1)
		index = ft_register_new_file(index, fd);
	else if (error == -1)
		return (-1);
	index = ft_get_the_good_file(index, fd);


	return (1);
}
