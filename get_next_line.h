/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:48:23 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/13 16:33:01 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>

typedef struct s_file	t_file;

struct					S_file
{
	int					file[3];
	t_file				*nxt;
	t_file				*pvs;
};

typdef t_file			*t_index;

int		ft_register_new_file(t_index index, const int fd);
int		ft_is_new_file(t_index index, const int fd);
int		get_next_line(const int fd, char **line);

#endif
