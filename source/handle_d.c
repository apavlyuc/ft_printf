/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:09:56 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/25 17:20:05 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

static int			get_nlen(long long num)
{
	size_t			len;

	if (num == 0)
		return (1);
	len = 0;
	while (num)
	{
		num /= 10;
		++len;
	}
	return (len);
}

static long long	get_data(va_list *args, t_param *param)
{
	if (param->specificator == CHAR_SIZE)
		return ((signed char)va_arg(*args, int));
	else if (param->specificator == SHORT_SIZE)
		return ((signed short int)va_arg(*args, int));
	else if (param->specificator == LONG_SIZE)
		return (va_arg(*args, long));
	else if (param->specificator == LONG_LONG_SIZE)
		return (va_arg(*args, long long));
	else if (param->specificator == SIZE_SIZE)
		return (va_arg(*args, ssize_t));
	else
		return (va_arg(*args, int));
}

static int			get_param_d_len(t_param *param, long long number, int *info)
{
	int				ret;

	info[0] = get_nlen(number);
	info[0] = (number == 0 && !param->accuracy) ? 0 : info[0];
	ret = (param->width > info[0]) ? param->width : info[0];
	info[0] = (param->accuracy > info[0])
		? param->accuracy : info[0];
	ret = (ret > info[0]) ? (ret) : (info[0]);
	info[2] = 0;
	if ((number >= 0 && (param->flags.plus || param->flags.space))
		|| number < 0)
	{
		info[2] = 1;
		++(info[0]);
		ret = (info[0] > ret) ? info[0] : ret;
		info[1] = (param->flags.minus) ? (0) : (ret - info[0]);
	}
	info[1] = (param->accuracy == -1 && param->flags.zero)
		? 0 : info[1];
	return (ret);
}

static void			create_digits(char *dst, int nlen, int pos, long long num)
{
	int				digit;

	while (nlen)
	{
		if (num)
		{
			digit = (num % 10);
			digit = (digit < 0) ? (-digit) : (digit);
			num /= 10;
		}
		else
			digit = 0;
		dst[--pos] = (digit + '0');
		--nlen;
	}
}

int					handle_d(char **dst, va_list *args, t_param *param)
{
	long long		number;
	int				len;
	int				info[3];

	number = get_data(args, param);
	len = get_param_d_len(param, number, info);
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	fill(*dst, ((param->flags.zero && !param->flags.minus &&
		param->accuracy == -1) ? '0' : ' '), len);
	create_digits(*dst, info[0], (param->flags.minus ? info[0] : len), number);
	if (info[2])
	{
		if (number < 0)
			(*dst)[info[1]] = '-';
		else
			(*dst)[info[1]] = param->flags.plus ? '+' : ' ';
	}
	return (len);
}
