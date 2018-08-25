/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:10:41 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/25 21:14:43 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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

int			update_param(const char **string, va_list *args, t_param *param)
{
	init_param(param);
	read_flags(string, param);
	read_width(string, args, param);
	read_accuracy(string, args, param);
	read_specificator(string, param);
	return (read_type(string, param));
}

void		init_param(t_param *param)
{
	param->flags.hash = 0;
	param->flags.minus = 0;
	param->flags.plus = 0;
	param->flags.space = 0;
	param->flags.zero = 0;
	param->width = 0;
	param->accuracy = NO_PRECISION;
	param->specificator = NO_SIZE;
	param->is_ptr = 0;
	param->data.ull = 0;
}

void		get_unsigned_arg(va_list *args, t_param *param)
{
	if (param->specificator == CHAR_SIZE)
		param->data.ull = (unsigned char)va_arg(*args, unsigned int);
	else if (param->specificator == SHORT_SIZE)
		param->data.ull = (unsigned short int)va_arg(*args, unsigned int);
	else if (param->specificator == LONG_SIZE)
		param->data.ull = (unsigned long)va_arg(*args, unsigned long);
	else if (param->specificator == LONG_LONG_SIZE)
		param->data.ull = va_arg(*args, unsigned long long);
	else if (param->specificator == SIZE_SIZE)
		param->data.ull = va_arg(*args, size_t);
	else
		param->data.ull = va_arg(*args, unsigned int);
}
