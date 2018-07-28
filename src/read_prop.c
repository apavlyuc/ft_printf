/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:01:32 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/28 18:25:58 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/ft_printf.h"

int			read_flags(const char **string, t_param *param)
{
	char	mark;

	mark = 1;
	while (mark == 1)
	{
		if (**string != '-' && **string != '+' && **string != ' ' &&
			**string != '#' && **string != '0')
			mark = 0;
		if (**string == '-')
			param->flags.minus = 1;
		else if (**string == '+')
			param->flags.plus = 1;
		else if (**string == ' ')
			param->flags.space = 1;
		else if (**string == '#')
			param->flags.hash = 1;
		else if (**string == '0')
			param->flags.zero = 1;
		if (mark)
			(*string)++;
	}
	return (1);
}

int			read_width(const char **string, va_list *args, t_param *param)
{
	if (**string == '*')
	{
		param->width.asterisk = 1;
		if ((param->width.width = va_arg(*args, int)) < 0)
		{
			param->width.width *= -1;
			param->flags.minus = 1;
		}
		++(*string);
	}
	else
	{
		param->width.width = atoi(*string);
		if (param->width.width || **string == '0')
			*string += get_number_len(param->width.width);
	}
	return (1);
}

int			read_accuracy(const char **string, va_list *args, t_param *param)
{
	if (**string == '.')
	{
		++(*string);
		if (**string == '*')
		{
			param->accuracy.asterisk = 1;
			param->accuracy.accuracy = va_arg(*args, int);
			++(*string);
		}
		else
		{
			param->accuracy.accuracy = atoi(*string);
			if (param->accuracy.accuracy || **string == '0')
				*string += get_number_len(param->accuracy.accuracy);
		}
	}
	return (1);
}

int			read_specificator(const char **string, t_param *param)
{
	int		len;

	len = 0;
	if (**string == 'h' || **string == 'l' || **string == 'j' ||
		**string == 'z')
		len = 1;
	if (**string == 'h' && *(*string + 1) == 'h' && (len = 2))
		param->specificator.hh = 1;
	else if (**string == 'l' && *(*string + 1) == 'l')
	{
		param->specificator.ll = 1;
		len = 2;
	}
	else if (**string == 'h')
		param->specificator.h = 1;
	else if (**string == 'l')
		param->specificator.l = 1;
	else if (**string == 'z')
		param->specificator.z = 1;
	else if (**string == 'j')
		param->specificator.j = 1;
	*string += len;
	return (1);
}

int			read_type(const char **string, t_param *param)
{
	if (**string != 's' && **string != 'S' && **string != 'p' &&
		**string != 'd' && **string != 'D' && **string != 'i' &&
		**string != 'o' && **string != 'O' && **string != 'u' &&
		**string != 'U' && **string != 'x' && **string != 'X' &&
		**string != 'c' && **string != 'C')
		return (-1);
	if (**string == 'S' || **string == 'C')
		param->specificator.l = 1;
	param->type = **string;
	++(*string);
	return (1);
}
