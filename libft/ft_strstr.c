/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:43:15 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/06 16:50:20 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		s2len;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	s2len = (int)ft_strlen((char*)s2);
	while (*s1)
	{
		while (*s1 == s2[i] && *s1 && s2len > i)
		{
			s1++;
			i++;
		}
		if (i == s2len)
		{
			s1 -= s2len;
			return ((char*)s1);
		}
		i = 0;
		s1++;
	}
	return (NULL);
}
