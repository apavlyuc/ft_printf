/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:15:15 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/25 21:14:25 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

static void			get_u_data(t_param *param, size_t *len, size_t *num_len)
{
	if (param->accuracy >= 0 && *num_len < (size_t)param->accuracy)
		*num_len = param->accuracy;
	if (param->accuracy == 0 && param->data.ull == 0)
		*num_len = 0;
	*len = param->width;
	if (*len < *num_len)
		*len = *num_len;
}

static int			handle_u_fill(char **dst, char const *tab, t_param *param)
{
	char			*wnb;
	size_t			len;
	size_t			num_len;
	int				base;

	base = get_length(tab);
	num_len = get_number_base_len(param->data.ull, base);
	get_u_data(param, &len, &num_len);
	*dst = malloc(sizeof(char) * (len + 1));
	fill(*dst, (param->flags.zero && !param->flags.minus &&
		param->accuracy == -1 ? '0' : ' '), len);
	wnb = (param->flags.minus) ? (*dst + num_len) : (*dst + len);
	write_number_base(wnb, num_len, param->data.ull, (t_base){base, tab});
	return (len);
}

int					handle_u(char **dst, va_list *args, t_param *param)
{
	int				ret;

	get_unsigned_arg(args, param);
	ret = handle_u_fill(dst, "0123456789", param);
	return (ret);
}
