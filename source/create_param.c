/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:49:26 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/24 22:20:14 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			create_param(char **dst, va_list *args, t_param *param)
{
	int		ret;

	if (param->type == 's')
		ret = handle_s(dst, args, param);
	else if (param->type == 'c')
		ret = handle_c(dst, args, param);
	else if (param->type == 'd')
		ret = handle_d(dst, args, param);
	else if (param->type == 'o')
		ret = handle_o(dst, args, param);
	else if (param->type == 'u')
		ret = handle_u(dst, args, param);
	else if (param->type == 'x' || param->type == 'X')
		ret = handle_x(dst, args, param);
	else
		ret = handle_other(dst, args, param);
	return (ret);
}
