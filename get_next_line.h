/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:48:23 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/20 18:38:50 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# define BUFF_SIZE 999

typedef struct s_file	t_file;

struct					s_file
{
	int					file[2];
	t_file				*nxt;
	t_file				*pvs;
};

typedef t_file			*t_index;

t_index					ft_register_new_file(t_index index, const int fd);
int						ft_is_new_file(t_index index, const int fd);
int						*ft_get_this_line(t_index index, char *buff,
							char **line);
int						get_next_line(const int fd, char **line);

#endif
