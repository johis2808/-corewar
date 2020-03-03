/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnbrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:07:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/03 10:11:55 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const long int	g_ten_pow[] = {
	1000000000000000000, 100000000000000000, 10000000000000000,
	1000000000000000, 100000000000000, 10000000000000, 1000000000000,
	100000000000, 10000000000, 1000000000, 100000000, 10000000, 1000000,
	100000, 10000, 1000, 100, 10, 1, 0
};

char		*ft_lnbrcat(char *dst, register long int n)
{
	register int	i;
	register int	j;

	i = 0;
	j = 0;
	*dst = '0';
	if (n < 0)
		dst[j++] = '-';
	while (g_ten_pow[i] && !(n / g_ten_pow[i]))
		++i;
	while (g_ten_pow[i])
	{
		if ((dst[j] = ((n / g_ten_pow[i]))) < 0)
			dst[j] *= -1;
		dst[j++] += '0';
		n %= g_ten_pow[i++];
	}
	return (dst);
}