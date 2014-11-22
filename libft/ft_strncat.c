/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:47:29 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/05 18:54:39 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		destlen;
	int		srclen;
	int		i;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen((char*)src);
	while ((destlen <= (destlen + srclen)) && ((int)n > 0))
	{
		dest[destlen] = src[i];
		destlen++;
		srclen--;
		i++;
		n--;
	}
	dest[destlen] = '\0';
	return (dest);
}
