/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:15:15 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/25 17:05:41 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

static void			get_o_data(t_param *param, size_t *s_pos, size_t *len,
					size_t *num_len)
{
	if (param->accuracy >= 0 && *num_len < (size_t)param->accuracy)
		*num_len = param->accuracy;
	if (param->flags.hash && param->data.ull > 0)
		++*num_len;
	if (!param->flags.hash && param->accuracy == 0 && param->data.ull == 0)
		*num_len = 0;
	*len = param->width;
	if (*len < *num_len)
		*len = *num_len;
	*s_pos = (param->flags.minus) ? (0) : (*len - *num_len);
	if (param->accuracy == -1 && param->flags.zero && len > num_len)
		*s_pos = (0);
}

int					handle_o_fill(char **dst, char const *tab, t_param *param)
{
	char			*wnb;
	size_t			s_pos;
	size_t			len;
	size_t			num_len;
	int				base;

	base = get_length(tab);
	num_len = get_number_base_len(param->data.ull, base);
	get_o_data(param, &s_pos, &len, &num_len);
	*dst = malloc(sizeof(char) * (len + 1));
	fill(*dst, (param->flags.zero && !param->flags.minus &&
		param->accuracy == -1 ? '0' : ' '), len);
	wnb = (param->flags.minus) ? (*dst + num_len) : (*dst + len);
	write_number_base(wnb, num_len, param->data.ull, (t_base){base, tab});
	if (param->flags.hash && param->data.ull > 0)
		(*dst)[s_pos] = '0';
	return (len);
}

int					handle_o(char **dst, va_list *args, t_param *param)
{
	int				ret;

	get_unsigned_arg(args, param);
	ret = handle_o_fill(dst, "01234567", param);
	return (ret);
}
