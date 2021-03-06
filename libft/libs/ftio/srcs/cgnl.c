/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:33:40 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/02 14:32:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio/gnl.h"

int				cgnl(const int fd, char **line, const char *crset)
{
	t_gnl_e	*cur;
	int		ret;

	cur = get_gnl_bufer(fd);
	if ((ret = cfdline_(cur->fd, line, &cur->sv, crset)) == 0)
		gnl_flush_elem(cur);
	return (ret);
}
