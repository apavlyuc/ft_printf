/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:00:13 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/14 18:11:37 by apavlyuc         ###   ########.fr       */
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
