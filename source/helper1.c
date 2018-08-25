/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:00:13 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/25 20:33:29 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			get_length(const char *string)
{
	int		length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}

int			get_wlength(const wchar_t *string)
{
	int		length;

	length = 0;
	while (*(string + length) != '\0')
		length++;
	return (length);
}

int			get_text_len(const char *string)
{
	int		len;

	len = 0;
	while (*(string + len))
	{
		if (*(string + len) == '%')
			break ;
		++len;
	}
	return (len);
}

int			get_bytes_in_wstr(const wchar_t *wstring, int count)
{
	int		len;

	len = 0;
	while (*wstring && count > 0)
	{
		if (*wstring <= 0x7F)
			len++;
		else if (*wstring <= 0x7FF)
			len += 2;
		else if (*wstring <= 0xFFFF)
			len += 3;
		else if (*wstring <= 0x10FFFF)
			len += 4;
		wstring++;
		count--;
	}
	return (len);
}

int			get_symbols_count(const wchar_t *string, int accuracy)
{
	int		ret;

	if (accuracy == -1)
		return (get_wlength(string));
	ret = 0;
	while (*string != '\0' && accuracy > 0)
	{
		accuracy -= get_bytes_in_wstr(string, 1);
		ret++;
		string++;
	}
	if (accuracy < 0)
		ret--;
	return (ret);
}
