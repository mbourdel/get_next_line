/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:54:02 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/11 18:47:43 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = ft_memalloc((ft_strlen(s1) + ft_strlen(s2)));
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	return (str);
}
