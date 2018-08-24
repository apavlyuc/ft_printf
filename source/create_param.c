/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:49:26 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/24 18:10:29 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			create_param(char **dst, va_list *args, t_param *param)
{
	int		ret;

	if (param->type == 's' || param->type == 'S')
		ret = handle_s(dst, args, param);
	else if (param->type == 'c' || param->type == 'C')
		ret = handle_c(dst, args, param);
	else if (param->type == 'd' || param->type == 'D' ||
			param->type == 'i')
		ret = handle_d(dst, args, param);
	else if (param->type == 'o' || param->type == 'O')
		ret = handle_o(dst, args, param);
	else if (param->type == 'u' || param->type == 'U')
		ret = handle_u(dst, args, param);
	else if (param->type == 'x' || param->type == 'X')
		ret = handle_x(dst, args, param);
	else
		ret = -1;
	return (ret);
}
