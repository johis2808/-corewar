/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_cos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 07:41:52 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/23 07:45:58 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath/k_cos.h"

double	ft_kernel_cos(double x, double y)
{
	double	hz;
	double	z;
	double	r;
	double	w;

	z = x * x;
	w = z * z;
	r = z * (C1 + z * (C2 + z * C3)) + w * w * (C4 + z * (C5 + z * C6));
	hz = 0.5 * z;
	w = 1.00000000000000000000e+00 - hz;
	return (w + (((1.00000000000000000000e+00 - w) - hz) + (z * r - x * y)));
}