/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:20:31 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/07 19:22:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void		ft_bzero(void *s, size_t n)
{
	char	*bytes;

	bytes = (char *)s;
	while (n-- > 0)
		*bytes++ = 0;
}
