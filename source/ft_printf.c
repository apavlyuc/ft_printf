/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:50:21 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/24 22:20:09 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ft_printf.h>

int			ft_printf(const char *string, ...)
{
	int		ret;
	int		tmp_ret;
	va_list	args;

	ret = 0;
	va_start(args, string);
	while (*string)
	{
		ret += print_text(&string);
		if (*string == '%')
		{
			string++;
			if ((tmp_ret = print_param(&string, &args)) < 0)
			{
				ret = tmp_ret;
				break ;
			}
			ret += tmp_ret;
		}
	}
	va_end(args);
	return (ret);
}

int			print_text(const char **string)
{
	int		len;

	len = get_text_len(*string);
	if (len)
		write(STDOUT_FILENO, *string, len);
	*string += len;
	return (len);
}

int			print_param(const char **string, va_list *args)
{
	int		ret;
	char	*dst;
	t_param	param;

	if ((ret = update_param(string, args, &param)) < 0)
		return (ret);
	dst = 0;
	ret = create_param(&dst, args, &param);
	if (ret > 0 && dst)
	{
		write(1, dst, ret);
		free(dst);
	}
	return (ret);
}
