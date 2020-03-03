/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:48:36 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/12 21:53:56 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftio.h"

/*
**	void		ft_putnbr(int n)
**	{
**		long	nb;
**
**		nb = n;
**		if (n < 0)
**		{
**			write(1, "-", 1);
**			nb = -nb;
**		}
**		if (nb / 10 > 0)
**			ft_putnbr(nb / 10);
**		ft_putchar(nb % 10 + '0');
**	}
*/

static const int	g_ten_pow[] = {
	1000000000, 100000000, 10000000,
	1000000, 100000, 10000, 1000,
	100, 10, 1, 0
};

void		ft_putnbr(register int n)
{
	register int	i;
	register int	j;
	char			buf[16];

	i = 0;
	j = 0;
	*buf = '0';
	if (n < 0)
		buf[j++] = '-';
	while (g_ten_pow[i] && !(n / g_ten_pow[i]))
		++i;
	while (g_ten_pow[i])
	{
		if ((buf[j] = ((n / g_ten_pow[i]))) < 0)
			buf[j] *= -1;
		buf[j++] += '0';
		n %= g_ten_pow[i++];
	}
	write(1, buf, j ? j : 1);
}
