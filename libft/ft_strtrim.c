/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:12:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/12 18:01:43 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblanc(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*ret;

	if (!s)
		return (0);
	i = 0;
	while (ft_isblanc(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && ft_isblanc(s[len]))
		len--;
	if (len < i)
		return (ret = ft_strdup (""));
	return (ret = ft_strsub(s, i, len - (size_t)i + 1));
}
