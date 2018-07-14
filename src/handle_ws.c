/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:36:20 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/14 21:22:35 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include "inc/ft_printf.h"

static void		change_values(int *accurecy, size_t step1, size_t *len, size_t step2)
{
	*accurecy += (int)step1;
	*len += (int)step2;
}

static size_t	get_param_sl_len(wchar_t *string, int accuracy, t_param *param)
{
	size_t		len;

	len = 0;
	while (*string != '\0' && accuracy > 0)
	{
		if (*string <= 0x7F)
			change_values(&accuracy, -1, &len, 1);
		else if (*string <= 0x7FF && accuracy >= 2)
			change_values(&accuracy, -2, &len, 2);
		else if (*string <= 0xFFFF && accuracy >= 3)
			change_values(&accuracy, -3, &len, 3);
		else if (*string <= 0x10FFFF && accuracy >= 4)
			change_values(&accuracy, -4, &len, 4);
		else
			break ;
		string++;
	}
	if (param->accuracy.accuracy > -1)
		len = (len < (size_t)param->accuracy.accuracy) ? len : param->accuracy.accuracy;
	len = (size_t)param->width.width > len ? param->width.width : len;
	return (len);
}

static void		insert(char **dst, wchar_t *src, t_param *param)
{
	size_t		len_string;
	size_t		len_param;

	len_param = 0;
	while (*(*dst + len_param))
		len_param++;
	len_string = param->accuracy.accuracy < 0 ? get_wlength(src) :
	get_param_sl_len(src, param->accuracy.accuracy, param);
	len_param--;
	len_string--;
	wchar_to_char(dst, src, len_param, len_string);
}

static void		rinsert(char **dst, wchar_t *src, t_param *param)
{
	(void)dst;
	(void)src;
	(void)param;
}

size_t			handle_ls(char **dst, va_list *args, t_param *param)
{
	wchar_t		*string;
	size_t		len;

	string = va_arg(*args, wchar_t*);
	string = string == NULL ? (wchar_t *)L"(null)" : string;
	len = param->accuracy.accuracy < 0 ? get_wlength(string) :
	get_param_sl_len(string, param->accuracy.accuracy, param);
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	fill(*dst, ' ', len);
	if (param->flags.minus == 0)
		insert(dst, string, param);
	else
		rinsert(dst, string, param);
	return (len);
}
