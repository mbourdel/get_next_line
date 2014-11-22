/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:35:03 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/22 20:38:42 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t size);

t_index	ft_register_new_file(t_index index, const int fd)
{
	t_index		new_file;

	if (!(new_file = (t_index)malloc(sizeof(t_file))))
		return (NULL);
	new_file->file = fd;
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
		if (tmp->file == fd)
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
			error = read(index->file, &buff[i++], 1);
	}
	if (buff[i - 1] == '\n')
		buff[i - 1] = '\0';
	if (error == -1)
		return (-1);
	line[0] = ft_strdup(buff);
	if (error == 0)
		return (0);
	return (1);
}

void	ft_destroy_everything(char *buff, t_index index)
{
	if (buff)
		free(buff);
	if (index)
	{
	if (index->pvs != NULL)
		index->nxt->pvs = index->pvs;
	if (index->nxt != NULL)
		index->pvs->nxt = index->nxt;
	if (index->nxt == NULL)
		index->pvs->nxt = NULL;
	if (index->pvs == NULL)
		index->nxt->pvs = NULL;
	free(index);
	}
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
	while (index->file != fd)
		index = index->nxt;
	if (ret == 1)
		ret = ft_get_this_line(index, buff, line);
	else
	{
		ft_get_this_line(index, buff, line);
		ft_destroy_everything(buff, index);
	}
	if (ret == 0)
		ft_destroy_everything(buff, index);
	return (ret);
}
