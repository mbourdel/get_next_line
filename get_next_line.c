/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:35:03 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/22 18:55:01 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t size);

t_index	ft_register_new_file(t_index index, const int fd)
{
	t_index		new_file;

	if (!(new_file = (t_index)malloc(sizeof(t_file))))
		return (NULL);
	new_file->file[0] = fd;
//	new_file->file[1] = 0;
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
	int		size;

	i = 1;
	error = 1;
	size = BUFF_SIZE;
	while (buff[i - 1] != '\n' && buff[i - 1] && error == 1
			&& i <= size)
	{
		if (i == size)
		{
			buff = ft_realloc(buff, BUFF_SIZE);
			size += BUFF_SIZE;
		}
		else
			error = read(index->file[0], &buff[i++], 1);
	}
	if (buff[i - 1] == '\n')
		buff[i - 1] = '\0';
	if (error == -1)
		return (-1);
	line[0] = ft_strdup(buff);
//	index->file[1] += 1;
	if (error == 0)
		return (0);
	return (1);
}

void	ft_distroy_everything(char *buff, t_index index)
{
	free(buff);
	if (index->pvs != NULL)
	{

	(t_index)free(index);
}

int		get_next_line(const int fd, char **line)
{
	static t_index	index = NULL;
	char			*buff;
	int				ret;

	index = ft_register_new_file(index, 1);
	buff = ft_memalloc(BUFF_SIZE);
	if ((ret = read(fd, &buff[0], 1)) == -1 || !line)
		return (-1);
	if (buff[0] == '\n')
		buff[0] = '\0';
	while (index->pvs != NULL)
		index = index->pvs;
	if ((ft_is_new_file(index, fd)) == 1)
		index = ft_register_new_file(index, fd);
	while (index->file[0] != fd)
		index = index->nxt;
	if (ret == 1)
		ret = ft_get_this_line(index, buff, line);
	else
	{
		ft_get_this_line(index, buff, line);
		ft_distroy_everything(buff, index);
	}
	return (ret);
}
