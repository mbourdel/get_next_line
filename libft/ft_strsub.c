/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:39:31 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/12 17:46:27 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (0);
	ret = ft_memalloc(len + 1);
	ret = ft_strncpy(ret, (s + start), len);
	return (ret);
}
