/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:49:26 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/14 14:49:36 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int			create_param(char **dst, va_list *args, t_param *param)
{
	int		ret;

	if (param->type == 's')
		ret = handle_s(dst, args, param);
	else
		ret = 0;
	return (ret);
}
