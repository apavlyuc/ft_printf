/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:10:41 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/14 21:22:24 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

void		fill(char *dst, char c, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		*(dst + i) = c;
		++i;
	}
	*(dst + len) = '\0';
}

static void	insert_wchar(char *dst, wchar_t src, int byte)
{
	if (byte == 1)
		*dst = (char)src;
	else if (byte == 2)
	{
		*dst = (char)((src & 0x3F) + 0x80);
		*(dst - 1) = (char)((src >> 6) + 0xC0);
	}
	else if (byte == 3)
	{
		*dst = (char)((src & 0x3F) + 0x80);
		*(dst - 1) = (char)(((src >> 6) & 0x3F) + 0x80);
		*(dst - 2) = (char)((src >> 12) + 0xE0);
	}
	else if (byte == 4)
	{
		*dst = (char)((src & 0x3F) + 0x80);
		*(dst - 1) = (char)(((src >> 6) & 0x3F) + 0x80);
		*(dst - 2) = (char)(((src >> 12) & 0x3F) + 0x80);
		*(dst - 3) = (char)((src >> 18) + 0xF0);
	}
}
void		wchar_to_char(char **dst, wchar_t *src, int lp, int ls)
{
	setlocale(LC_ALL, "");
	int		i;

	while (lp >= 0 && ls >= 0)
	{
		if (*src <= 0x7F)
			i = 1;
		else if (*src <= 0x7FF)
			i = 2;
		else if (*src <= 0xFFFF)
			i = 3;
		else if (*src <= 0x10FFFF)
			i = 4;
		printf("symbol = %lc\n", *(src + ls));
		insert_wchar((*dst + lp), *(src + ls), i);
		lp -= i;
		ls -= 1;
		printf("%s\n", (*dst + lp));
	}
}

void		init_param(t_param *param)
{
	param->flags.hash = 0;
	param->flags.minus = 0;
	param->flags.plus = 0;
	param->flags.space = 0;
	param->flags.zero = 0;
	param->width.width = 0;
	param->width.asterisk = 0;
	param->accuracy.accuracy = -1;
	param->accuracy.asterisk = 0;
	param->specificator.h = 0;
	param->specificator.hh = 0;
	param->specificator.j = 0;
	param->specificator.l = 0;
	param->specificator.ll = 0;
	param->specificator.z = 0;
}
