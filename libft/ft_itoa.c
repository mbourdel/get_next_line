/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:35:36 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/11 16:47:35 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	buff[22];
	char	*str;
	int		i;
	int		ntmp;

	i = 0;
	ntmp = n;
	if (n < 0)
		ntmp = -n;
	while (ntmp > 0)
	{
		buff[i++] = (ntmp % 10) + 48;
		ntmp = ntmp / 10;
	}
	if (n < 0)
		buff[i++] = '-';
	str = ft_memalloc((size_t)i + 1);
	if (n == -2147483648)
		return ("-2147483648");
	else if (n == 0)
		str[0] = '0';
	while (--i >= 0)
		str[ntmp++] = buff[i];
	return (str);
}
