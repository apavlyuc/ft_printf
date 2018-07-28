/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:49:26 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/28 17:28:48 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int			create_param(char **dst, va_list *args, t_param *param)
{
	int		ret;

	if (param->type == 's' || param->type == 'S')
		ret = handle_s(dst, args, param);
	else if (param->type == 'c' || param->type == 'C')
		ret = handle_c(dst, args, param);
	else
		ret = 0;
	return (ret);
}
