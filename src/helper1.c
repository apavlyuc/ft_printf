/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:00:13 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/14 19:45:05 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int			get_length(const char *string)
{
	int		length;

	length = 0;
	while (*(string + length))
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

int			get_number_len(long long int number)
{
	int		len;

	if (number == 0)
		return (1);
	len = 0;
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len);
}

size_t			get_wlength(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			len++;
		else if (*str <= 0x7FF)
			len += 2;
		else if (*str <= 0xFFFF)
			len += 3;
		else if (*str <= 0x10FFFF)
			len += 4;
		str++;
	}
	return (len);
}
