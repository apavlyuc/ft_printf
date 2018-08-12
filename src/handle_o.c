/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:14:16 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/12 22:24:16 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdlib.h>

static unsigned long long	get_data(va_list *args, t_param *param, char *base)
{
	if (param->type == 'u')
		base = "0123456789";
	else if (param->type = 'o')
		base = "01234567";
	else if (param->type == 'x')
		base = "0123456789abcdef";
	else if (param->type == 'X')
		base = "0123456789ABCDEF";
	if (param->specificator.hh == 1)
		return ((unsigned char)va_arg(*args, unsigned int));
	else if (param->specificator.h == 1)
		return ((unsigned short int)va_arg(*args, unsigned int));
	else if (param->specificator.l == 1)
		return ((unsigned long)va_arg(*args, unsigned long));
	else if (param->specificator.ll == 1 ||
			param->specificator.j == 1)
		return ((unsigned long long)va_arg(*args, unsigned long long));
	else if (param->specificator.z == 1)
		return (va_arg(*args, ssize_t));
	else
		return (va_arg(*args, unsigned int));
}

static int			get_param_o_len(t_param *param, long long number, int *info)
{
	int				ret;

	info[0] = get_nlen(number);
	info[0] = (number == 0 && !param->accuracy.accuracy) ? 0 : info[0];
	ret = (param->width.width > info[0]) ? param->width.width : info[0];
	info[0] = (param->accuracy.accuracy > info[0]) ? param->accuracy.accuracy : info[0];
	ret = (ret > info[0]) ? (ret) : (info[0]);
	info[2] = 0;
	if ((number >= 0 && (param->flags.plus || param->flags.space)) || number < 0)
	{
		info[2] = 1;
		++(info[0]);
		ret = (info[0] > ret) ? info[0] : ret;
		info[1] = (param->flags.minus) ? (0) : (ret - info[0]);
	}
	info[1] = (param->accuracy.accuracy == -1 && param->flags.zero) ? 0 : info[1];
	return (ret);
}

int							handle_o(char **dst, va_list *args, t_param *param)
{
	int						number;
	int						ret;
	int						info[3];
	char					*base;

	number = get_data(args, param, base);
	ret = 0;
	return (ret);
}