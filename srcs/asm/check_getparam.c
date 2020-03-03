/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_getparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 07:06:39 by thberrid          #+#    #+#             */
/*   Updated: 2019/11/08 07:11:06 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** take an ocp (REG_CODE / DIR_CODE / IND_CODE)
** and look in g_op_tab.args
** en utilisant les bitwise operator
** par exemple : par exemple pour `ld` on a {T_DIR | T_IND, T_REG}
** ce qui donne {2 | 4, 1}, en binaire {0010 | 0100, 0001}
** et du coup le | il superpose tout c'est trop pratique et
** COMME PAR HASARD OUPS aucun bit ne se superpose
** ca donne {0110 | 0001} et du coup on peut regarder facilement
*/

int			is_paramtype_allowed(char param_type, t_instruct *inst, int i)
{
	if (param_type == IND_CODE)
		param_type = T_IND;
	if ((g_op_tab[inst->id].args[i] ^ param_type) < g_op_tab[inst->id].args[i])
		return (1);
	return (0);
}

int			get_paramtype(char **param_raw, t_instruct *inst, int i, int j)
{
	int		param_type;
	int		ret;

	param_type = 0;
	ret = 1;
	if (param_raw[i][j] == 'r' && (ret = param_raw[i][j + 1])
		&& (ret = ft_checkchar(&param_raw[i][j + 1], REG_CHAR)))
		param_type = REG_CODE;
	else if (ret == 0)
		return (0);
	else if (param_raw[i][j] == '%'
		&& (ret = is_str_valid(&(param_raw[i][j + 1]))))
		param_type = DIR_CODE;
	else if (ret == 0)
		return (0);
	else if ((ret = is_str_valid(&(param_raw[i][j]))))
		param_type = IND_CODE;
	else if (ret == 0)
		return (0);
	if (!is_paramtype_allowed(param_type, inst, i))
		return (0);
	return (param_type);
}

/*
** 1 check if the number of arguments is correct
** 2 then do str split (str ',')
** 3 encode the ocp (and verify if each parameter has an allowed type)
** 4 save it into the t_instruct
** 5 make money
*/

int			ft_getparams(char **line, t_instruct *inst)
{
	char	**param_raw;
	int		param_len;
	int		err;

	param_len = get_paramlen(inst->id);
	err = 1;
	if (param_len != 1 + ft_strcountchar(*line, SEPARATOR_CHAR))
		err = -1;
	if (!(param_raw = ft_strsplit(*line, SEPARATOR_CHAR)))
		err = -1;
	if (!(inst->ocp = get_ocp(param_raw, param_len, inst)))
		err = -1;
	if (!param_to_inst(param_raw, inst, line))
		err = -1;
	free_split(param_raw);
	return (err);
}

t_arg_type	get_ocp(char **param_raw, int param_len, t_instruct *inst)
{
	t_arg_type	ocp;
	int			i;
	int			j;
	char		param_type;

	i = 0;
	ocp = 0;
	(void)param_len;
	while (param_raw[i])
	{
		j = 0;
		while (ft_isspace(param_raw[i][j]))
			j++;
		if (!(param_type = get_paramtype(param_raw, inst, i, j)))
			return (0);
		ocp += ((param_type << (3 - i) * 2));
		inst->params_bits[i] = get_octet(inst->id, param_type);
		i++;
	}
	return (ocp);
}

/*
** take the opcode,
** return the nmbr of argument
*/

int			get_paramlen(int opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (opcode == g_op_tab[i].id)
			return (g_op_tab[i].arg_cnt);
		i++;
	}
	return (-1);
}
