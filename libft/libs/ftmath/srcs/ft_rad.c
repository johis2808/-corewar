/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:46:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/15 12:30:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

double	ft_rad(double a)
{
	return (a / 180.0 * FT_PI);
}

float	ft_radf(float a)
{
	return (a / 180.0F * (float)FT_PI);
}
