/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:48:36 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 04:11:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static const unsigned long int	g_ten_pow[] = {
	1000000000000000000, 100000000000000000, 10000000000000000,
	1000000000000000, 100000000000000, 10000000000000, 1000000000000,
	100000000000, 10000000000, 1000000000, 100000000, 10000000, 1000000,
	100000, 10000, 1000, 100, 10, 1, 0
};

void		ft_putlunbr(register unsigned long int n)
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
