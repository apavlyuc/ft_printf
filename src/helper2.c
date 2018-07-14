/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:10:41 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/14 18:11:27 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

void		fill(char *dst, char c, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		*(dst + i) = c;
		++i;
	}
	*(dst + len) = '\0';
}

void		init_param(t_param *param)
{
	param->flags.hash = 0;
	param->flags.minus = 0;
	param->flags.plus = 0;
	param->flags.space = 0;
	param->flags.zero = 0;
	param->width.width = 0;
	param->width.asterisk = 0;
	param->accuracy.accuracy = -1;
	param->accuracy.asterisk = 0;
	param->specificator.h = 0;
	param->specificator.hh = 0;
	param->specificator.j = 0;
	param->specificator.l = 0;
	param->specificator.ll = 0;
	param->specificator.z = 0;
}