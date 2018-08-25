/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:01:32 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/25 17:26:15 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		read_flags(const char **string, t_param *param)
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
}

void		read_width(const char **string, va_list *args, t_param *param)
{
	if (**string == '*')
	{
		if ((param->width = va_arg(*args, int)) < 0)
		{
			param->width *= -1;
			param->flags.minus = 1;
		}
		++(*string);
	}
	else
	{
		while (**string >= '0' && **string <= '9')
		{
			param->width = param->width * 10 + (**string - '0');
			++*string;
		}
	}
}

void		read_accuracy(const char **string, va_list *args, t_param *param)
{
	if (**string == '.')
	{
		param->accuracy = 0;
		++(*string);
		if (**string == '*')
		{
			param->accuracy = va_arg(*args, int);
			if (param->accuracy < 0)
				param->accuracy = -1;
			++(*string);
		}
		else
		{
			while (**string >= '0' && **string <= '9')
			{
				param->accuracy = param->accuracy * 10 + (**string - '0');
				++*string;
			}
		}
	}
}

void		read_specificator(const char **string, t_param *param)
{
	int		len;

	len = 0;
	if (**string == 'h' || **string == 'l' || **string == 'j' ||
		**string == 'z')
		len = 1;
	if (**string == 'h' && *(*string + 1) == 'h' && (len = 2))
		param->specificator = CHAR_SIZE;
	else if (**string == 'l' && *(*string + 1) == 'l')
	{
		param->specificator = LONG_LONG_SIZE;
		len = 2;
	}
	else if (**string == 'h')
		param->specificator = SHORT_SIZE;
	else if (**string == 'l')
		param->specificator = LONG_SIZE;
	else if (**string == 'z')
		param->specificator = SIZE_SIZE;
	else if (**string == 'j')
		param->specificator = LONG_LONG_SIZE;
	*string += len;
}

int			read_type(const char **string, t_param *param)
{
	if (**string != 's' && **string != 'S' && **string != 'p' &&
		**string != 'd' && **string != 'D' && **string != 'i' &&
		**string != 'o' && **string != 'O' && **string != 'u' &&
		**string != 'U' && **string != 'x' && **string != 'X' &&
		**string != 'c' && **string != 'C' && **string != '%')
		return (-1);
	if (**string == 'S' || **string == 'C' || **string == 'D' ||
		**string == 'U' || **string == 'O')
	{
		param->type = (**string + ('a' - 'A'));
		param->specificator = LONG_SIZE;
	}
	else if (**string == 'i')
		param->type = 'd';
	else
		param->type = **string;
	++(*string);
	return (1);
}
