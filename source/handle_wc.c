/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:30:15 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/25 21:10:06 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>

static void	insert_wint(char *dst, wint_t src, int byte)
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
}

static int	get_param_lc_len(wint_t c, t_param *param, int *spaces)
{
	int		len;
	int		bytes;

	if (c == 0)
		bytes = 1;
	else
		bytes = get_bytes_in_wstr((const wchar_t *)(&c), 1);
	len = param->width < bytes ? bytes : param->width;
	*spaces = (len - bytes) > 0 ? (len - bytes) : 0;
	return (len);
}

static void	insert(char *dst, wint_t c)
{
	int		i;

	i = 0;
	if (c <= 0x7F)
		i = 1;
	else if (c <= 0x7FF)
		i = 2;
	else if (c <= 0xFFFF)
		i = 3;
	else if (c <= 0x10FFFF)
		i = 4;
	insert_wint(dst, c, i);
}

static void	rinsert(char *dst, wint_t c)
{
	insert(dst, c);
}

int			handle_lc(char **dst, va_list *args, t_param *param)
{
	wint_t	c;
	int		len;
	int		spaces;

	c = va_arg(*args, wint_t);
	len = get_param_lc_len(c, param, &spaces);
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	fill(*dst, ' ', len);
	if (param->flags.minus == 0)
		insert(*dst, c);
	else
		rinsert(*dst, c);
	return (len);
}
