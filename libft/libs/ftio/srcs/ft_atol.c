/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:11:16 by abaurens          #+#    #+#             */
/*   Updated: 2019/07/04 02:26:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "ftio.h"

long	ft_atol(const char *str)
{
	return (ft_atol_base(str, "0123456789"));
}
