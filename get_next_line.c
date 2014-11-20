/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:35:03 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/20 19:38:22 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_index	ft_register_new_file(t_index index, const int fd)
{
	t_index		new_file;

	if (!(new_file = (t_index)malloc(sizeof(t_file))))
		return (NULL);
	new_file->file[0] = fd;
	new_file->file[1] = 0;
	new_file->nxt = index;
	if (index != NULL)
		index->pvs = new_file;
	new_file->pvs = NULL;
	return (new_file);
}

int		ft_is_new_file(t_index index, const int fd)
{
	t_index		tmp;

	tmp = index;
	while (tmp != NULL)
	{
		if (tmp->file[0] == fd)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}

int		ft_get_this_line(t_index index, char *buff, char **line)
{
	int		i;
	int		error;

	i = 1;
	error = 1;
	while (buff[i - 1] != '\n' && buff[i - 1] && error == 1
			&& i < BUFF_SIZE)
		error = read(index->file[0], &buff[i++], 1);
	if (error == -1)
		return (-1);
	line[index->file[1]] = ft_strdup(buff);
	index->file[1] += 1;
	if (error == 0)
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_index	index = NULL;
	static int		i = 0;
	char			*buff;
	int				ret;

	index = ft_register_new_file(index, 1);
	buff = ft_memalloc(BUFF_SIZE);
	if (read(fd, &buff[0], 1) == -1 || !line)
		return (-1);
	if (buff[0] == '\n')
		buff[0] = '\0';
	while (index->pvs != NULL)
		index = index->pvs;
	if ((ft_is_new_file(index, fd)) == 1)
		index = ft_register_new_file(index, fd);
	while (index->file[0] != fd)
		index = index->nxt;
	ret = ft_get_this_line(index, buff, line);
	ft_putstr(line[i]);
	i++;
	free(buff);
	return (ret);
}
