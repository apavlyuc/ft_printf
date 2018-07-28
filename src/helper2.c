/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:10:41 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/28 17:01:12 by apavlyuc         ###   ########.fr       */
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

int			get_number_len(long long int number)
{
	int		len;

	if (number == 0)
		return (1);
	len = 0;
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len);
}

int			update_param(const char **string, va_list *args, t_param *param)
{
	int ret;

	ret = 0;
	init_param(param);
	ret += read_flags(string, param);
	ret += read_width(string, args, param);
	ret += read_accuracy(string, args, param);
	ret += read_specificator(string, param);
	ret += read_type(string, param);
	return (ret == 5 ? 5 : -1);
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
