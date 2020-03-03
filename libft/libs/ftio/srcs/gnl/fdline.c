/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdline.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:17:10 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/14 07:24:17 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftio/gnl.h"
#include "ftlib.h"

char		fdline_(const int fd, char **line, char **save)
{
	int		n;
	size_t	l;
	char	*tmp;
	char	buff[GNL_BUF + 1];

	while ((l = ft_idxof('\n', *save)) == ft_idxof(0, *save))
	{
		if ((n = read(fd, buff, GNL_BUF)) < 0)
			return (-1);
		if (n == 0)
			break ;
		buff[n] = 0;
		if (ft_strlen(buff) < (size_t)n || !(tmp = gnl_cat_(*save, buff, -1)))
			return (-1);
		free(*save);
		*save = tmp;
	}
	tmp = *save;
	if (tmp && !(*line = gnl_cat_(NULL, tmp, l)))
		return (-1);
	n = (tmp && (!tmp[l] || (tmp[l] == '\n' && ++l)));
	*save = ((tmp && tmp[l]) ? gnl_cat_(0x0, tmp + l, -1) : 0x0);
	free(tmp);
	return (n != 0 || *save != NULL);
}
