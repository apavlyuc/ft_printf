/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:36:20 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/24 19:45:14 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "inc/ft_printf.h"

static void	insert_wchar(char *dst, wchar_t src, int byte)
{
	if (byte == 1)
		*(dst) = (char)src;
	else if (byte == 2)
	{
		*(dst) = (char)((src >> 6) + 0xC0);
		*(dst + 1) = (char)((src & 0x3F) + 0x80);
	}
	else if (byte == 3)
	{
		*(dst) = (char)((src >> 12) + 0xE0);
		*(dst + 1) = (char)(((src >> 6) & 0x3F) + 0x80);
		*(dst + 2) = (char)((src & 0x3F) + 0x80);
	}
	else if (byte == 4)
	{
		*(dst) = (char)((src >> 18) + 0xF0);
		*(dst + 1) = (char)(((src >> 12) & 0x3F) + 0x80);
		*(dst + 2) = (char)(((src >> 6) & 0x3F) + 0x80);
		*(dst + 3) = (char)((src & 0x3F) + 0x80);
	}
	write(1, dst, byte);
}

static int		get_param_sl_len(wchar_t *string, t_param *param, int *spaces, int *symbols)
{
	int			len;
	int			bytes;

	*symbols = get_symbols_count(string, param->accuracy.accuracy);
	bytes = get_bytes_in_wstr(string, *symbols); // bytes in ${symbols}
	len = param->width.width < bytes ? bytes : param->width.width; // min bytes count for output
	*spaces = len - bytes > 0 ? (len - bytes) : 0;
	return (len);
}

static int		insert(char *dst, wchar_t *src, int spaces, int accuracy)
{
	int			i;
	int			ret;

	ret = 0;
	while (spaces-- > 0)
		write(1, " ", 1);
	spaces = accuracy >= 0 ? 0 : 1;
	while (*src && (spaces || accuracy >= get_bytes_in_wstr(src, 1)))
	{
		if (*src <= 0x7F)
			i = 1;
		else if (*src <= 0x7FF)
			i = 2;
		else if (*src <= 0xFFFF)
			i = 3;
		else if (*src <= 0x10FFFF)
			i = 4;
		insert_wchar(dst, *src, i);
		accuracy -= get_bytes_in_wstr(src, 1);
		src++;
		dst += i;
	}
	return (ret);
}

static int		rinsert(char **dst, wchar_t *src, t_param *param)
{
	(void)dst;
	(void)src;
	(void)param;

	return (0);
}

int				handle_ls(char **dst, va_list *args, t_param *param)
{
	wchar_t		*string;
	int			len;
	int			spaces;
	int			symbols;

	string = va_arg(*args, wchar_t*);
	string = string == NULL ? (wchar_t *)L"(null)" : string;
	len = get_param_sl_len(string, param, &spaces, &symbols);
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	fill(*dst, ' ', len);
	if (param->flags.minus == 0)
		insert((*dst + spaces), string, spaces, param->accuracy.accuracy);
	else
		rinsert(dst, string, param);
	**dst = '\0';
	return (len);
}
