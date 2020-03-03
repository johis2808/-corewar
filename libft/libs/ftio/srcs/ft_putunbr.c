/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:48:36 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 21:54:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static const unsigned int	g_ten_pow[] = {
	1000000000, 100000000, 10000000,
	1000000, 100000, 10000, 1000,
	100, 10, 1, 0
};

void		ft_putunbr(register unsigned int n)
{
	register int	i;
	register int	j;
	char			buf[16];

	i = 0;
	j = 0;
	*buf = '0';
	while (g_ten_pow[i] && !(n / g_ten_pow[i]))
		++i;
	while (g_ten_pow[i])
	{
		buf[j++] = ((n / g_ten_pow[i])) + '0';
		n %= g_ten_pow[i++];
	}
	write(1, buf, j ? j : 1);
}
