/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:15:15 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/24 23:49:09 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

int					handle_x_fill(char **dst, char const *tab, t_param *param)
{
	char			*wnb;
	size_t			s_pos;
	size_t			len;
	size_t			num_len;
	int				base;

	base = get_length(tab);
	num_len = get_number_base_len(param->data.ull, base);
	if (param->flags.hash)
		num_len += 2;
	len = param->width;
	if (len < num_len)
		len = num_len;
	*dst = malloc(sizeof(char) * (len + 1));
	fill(*dst, (param->flags.zero ? '0' : ' '), len);
	wnb = (param->flags.minus) ? (*dst + num_len) : (*dst + len);
	s_pos = (param->flags.minus) ? (1) : (len - num_len + 1);
	write_number_base(wnb, num_len, param->data.ull, (t_base){base, tab});
	if (param->flags.hash)
		(*dst)[s_pos] = param->type;
	return (len);
}

int					handle_x(char **dst, va_list *args, t_param *param)
{
	int				ret;

	get_unsigned_arg(args, param);
	if (param->type == 'x')
		ret = handle_x_fill(dst, "0123456789abcdef", param);
	else
		ret = handle_x_fill(dst, "0123456789ABCDEF", param);
	return (ret);
}
