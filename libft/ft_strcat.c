/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:08:15 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/06 16:48:25 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		destlen;
	int		srclen;
	int		i;

	i = 0;
	destlen = (int)ft_strlen(dest);
	srclen = (int)ft_strlen((char*)src);
	while (destlen <= (destlen + srclen))
	{
		dest[destlen] = src[i];
		destlen++;
		srclen--;
		i++;
	}
	dest[destlen] = '\0';
	return (dest);
}
