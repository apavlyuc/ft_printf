/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:14:16 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/24 22:50:03 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

static unsigned long long	get_data(va_list *args, t_param *param)
{
	if (param->specificator.hh)
		return ((unsigned char)va_arg(*args, unsigned int));
	else if (param->specificator.h)
		return ((unsigned short int)va_arg(*args, unsigned int));
	else if (param->specificator.l)
		return ((unsigned long)va_arg(*args, unsigned long));
	else if (param->specificator.ll ||
			param->specificator.j)
		return ((unsigned long long)va_arg(*args, unsigned long long));
	else if (param->specificator.z)
		return (va_arg(*args, ssize_t));
	else
		return (va_arg(*args, unsigned int));
}

static int					get_param_o_len(t_param *param,
							long long number, int *info)
{
	int						ret;

	info[0] = (number == 0 && !param->accuracy) ? 0 : info[0];
	ret = (param->width > info[0]) ? param->width : info[0];
	info[0] = (param->accuracy > info[0])
		? param->accuracy : info[0];
	ret = (ret > info[0]) ? (ret) : (info[0]);
	info[2] = 0;
	if ((number >= 0 && (param->flags.plus || param->flags.space))
		|| number < 0)
	{
		info[2] = 1;
		++(info[0]);
		ret = (info[0] > ret) ? info[0] : ret;
		info[1] = (param->flags.minus) ? (0) : (ret - info[0]);
	}
	info[1] = (param->accuracy == -1 &&
		param->flags.zero) ? 0 : info[1];
	return (ret);
}

int							handle_o(char **dst, va_list *args, t_param *param)
{
	int						number;
	int						ret;
	int						info[3];

	(void)args;
	(void)dst;
	(void)info;
	(void)get_param_o_len;
	number = get_data(args, param);
	ret = 0;
	return (ret);
}
