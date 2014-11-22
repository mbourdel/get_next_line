/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:17:54 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/11 19:11:08 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ret;
	size_t	retlen;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	retlen = ft_strlen(s);
	ret = ft_memalloc(retlen + 1);
	while (*s)
	{
		ret[i++] = f(*s);
		s++;
	}
	return (ret);
}
