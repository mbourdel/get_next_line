/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:34:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/11 15:53:48 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*rev;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!(rev = ft_memalloc(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		rev[i] = s[i];
		i++;
	}
	i--;
	while (i >= 0)
		s[x++] = rev[i--];
	free(rev);
	return (s);
}
