/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:06:38 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/11 18:20:08 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;

	tmp = ft_memalloc(n + 1);
	tmp = ft_memcpy(tmp, src, n);
	dest = ft_memcpy(dest, tmp, n);
	free(tmp);
	return (dest);
}
