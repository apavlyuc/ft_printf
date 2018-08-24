/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 22:03:37 by modnosum          #+#    #+#             */
/*   Updated: 2018/08/24 22:22:10 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

int			handle_other(char **dst, va_list *args, t_param *param)
{
	size_t	len;

	(void)args;
	len = (param->width > 0) ? (param->width) : (1);
	*dst = malloc(sizeof(char) * len);
	fill(*dst, ' ', len);
	if (param->flags.minus)
		(*dst)[0] = '%';
	else
		(*dst)[len - 1] = '%';
	return (len);
}
