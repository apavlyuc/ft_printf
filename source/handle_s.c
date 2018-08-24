/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:58:25 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/24 18:08:53 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>

static void	insert(char **dst, char *src, t_param *param)
{
	int		len_string;
	int		len_param;

	len_param = 0;
	while (*(*dst + len_param))
		len_param++;
	len_string = get_length(src);
	if (param->accuracy.accuracy > -1)
		len_string = len_string < param->accuracy.accuracy ?
			len_string : param->accuracy.accuracy;
	len_param--;
	len_string--;
	while (len_string != -1 && len_param != -1)
		*(*dst + len_param--) = *(src + len_string--);
}

static void	rinsert(char **dst, char *src, t_param *param)
{
	int		len_string;
	int		len_param;

	len_param = 0;
	len_string = get_length(src);
	if (param->accuracy.accuracy > -1)
		len_string = len_string < param->accuracy.accuracy ?
			len_string : param->accuracy.accuracy;
	while (len_param < len_string && *(*dst + len_param) && *(src + len_param))
	{
		*(*dst + len_param) = *(src + len_param);
		len_param++;
	}
}

static int	get_param_s_len(t_param *param, int init_len)
{
	int		len;

	if (param->accuracy.accuracy > -1)
		init_len = init_len < param->accuracy.accuracy ?
			init_len : param->accuracy.accuracy;
	len = (param->width.width > init_len) ? param->width.width : init_len;
	return (len);
}

int			handle_s(char **dst, va_list *args, t_param *param)
{
	char	*string;
	int		len;

	if (param->specificator.l == 1)
		return (handle_ls(dst, args, param));
	string = va_arg(*args, char*);
	string = string == NULL ? (char *)"(null)" : string;
	len = get_param_s_len(param, get_length(string));
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	fill(*dst, ' ', len);
	if (param->flags.minus == 0)
		insert(dst, string, param);
	else
		rinsert(dst, string, param);
	return (len);
}
