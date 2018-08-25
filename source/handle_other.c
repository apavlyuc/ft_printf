/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 22:03:37 by modnosum          #+#    #+#             */
/*   Updated: 2018/08/25 17:45:21 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

int			handle_other(char **dst, va_list *args, t_param *param)
{
	size_t	len;

	if (param->type == '%')
	{
		len = (param->width > 0) ? (param->width) : (1);
		*dst = malloc(sizeof(char) * (len + 1));
		fill(*dst, ' ', len);
		if (param->flags.minus)
			(*dst)[0] = '%';
		else
			(*dst)[len - 1] = '%';
	}
	else
	{
		param->is_ptr = 1;
		param->data.ull = (t_ull)va_arg(*args, void*);
		param->flags.hash = 1;
		param->type = 'x';
		param->specificator = LONG_LONG_SIZE;
		len = handle_x_fill(dst, "0123456789abcdef", param);
	}
	return (len);
}
