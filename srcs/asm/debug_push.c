/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 06:03:53 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/10 06:18:00 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			push_str(char *dest, char *src, int len, int start)
{
	ft_bzero(dest, len);
	ft_strncpy(dest, src, len);
	return (start + 1);
}

int			push_label(char **line, t_instruct *inst, int *cflag)
{
	int		len;

	len = 0;
	while (ft_isspace(**line))
		(*line)++;
	while ((*line)[len] && (*line)[len] != LABEL_CHAR
		&& !ft_isspace((*line)[len]))
		len++;
	if ((*line)[len] == LABEL_CHAR)
	{
		if (ft_deflab(inst, cflag, *line, len) < 0)
			return (-9);
		(*line) += (len + 1);
	}
	while (ft_isspace(**line))
		(*line)++;
	while ((*line)[len] && (*line)[len] != DIRECT_CHAR
		&& (*line)[len] != LABEL_CHAR && !ft_isspace((*line)[len]))
		len++;
	return (len);
}

int			push_param(char **line)
{
	int		len;

	len = 0;
	while (ft_isspace(**line))
		(*line)++;
	while ((*line)[len] && (*line)[len] != SEPARATOR_CHAR
		&& !ft_isspace((*line)[len]))
		len++;
	return (len);
}

int			push_paramtype(char **line, int *len)
{
	int		param_type;

	param_type = IND_CODE;
	if (**line == 'r' && *len-- && (*line)++)
		param_type = REG_CODE;
	if (**line == DIRECT_CHAR && *len-- && (*line)++)
		param_type = DIR_CODE;
	return (param_type);
}
