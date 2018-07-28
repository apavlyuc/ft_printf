/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:36:20 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/28 19:05:00 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "inc/ft_printf.h"

static void		insert_wchar(char *dst, wchar_t src, int byte)
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

static int		get_param_sl_len(wchar_t *str, t_param *p, int *sp, int *smb)
{
	int			len;
	int			bytes;

	*smb = get_symbols_count(str, p->accuracy.accuracy);
	bytes = get_bytes_in_wstr(str, *smb);
	len = p->width.width < bytes ? bytes : p->width.width;
	*sp = (len - bytes) > 0 ? (len - bytes) : 0;
	return (len);
}

static void		insert(char *dst, wchar_t *src, int spaces, int symbols)
{
	int			i;

	while (spaces-- > 0)
		write(1, " ", 1);
	while (*src && symbols > 0)
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
		symbols--;
		src++;
		dst += i;
	}
}

static void		rinsert(char *dst, wchar_t *src, int spaces, int symbols)
{
	insert(dst, src, 0, symbols);
	while (spaces-- > 0)
		write(1, " ", 1);
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
		insert(*dst, string, spaces, symbols);
	else
		rinsert(*dst, string, spaces, symbols);
	**dst = '\0';
	return (len);
}
