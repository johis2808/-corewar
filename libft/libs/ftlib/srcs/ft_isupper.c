/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:07:56 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/15 16:45:15 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

char	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
