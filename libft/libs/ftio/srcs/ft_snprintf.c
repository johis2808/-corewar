/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:15:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/11/03 17:27:46 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "ftlib.h"
#include "ftio.h"

int			ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int		l;
	char	*tmp;

	tmp = NULL;
	if (size == 0)
		return (0);
	if ((l = ft_vasprintf(&tmp, format, ap)) < 0 || !tmp)
		return (-1);
	if ((size_t)l >= size)
		l = size - 1;
	ft_strcpy(str, tmp);
	free(tmp);
	return (l);
}

int			ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int		l;
	va_list	lst;

	va_start(lst, format);
	l = ft_vsnprintf(str, size, format, lst);
	va_end(lst);
	return (l);
}
