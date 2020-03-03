/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_cross.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:31:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/18 10:49:55 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftvectors/vec2/t_vec2_t.h"

t_vec2i		v2i_cross(t_vec2i *u)
{
	t_vec2i	v;

	v.x = u->y;
	v.y = -u->x;
	return (v);
}
