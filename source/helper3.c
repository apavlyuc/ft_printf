/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 23:02:31 by modnosum          #+#    #+#             */
/*   Updated: 2018/08/24 23:38:13 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			get_number_base_len(t_ull number, int base)
{
	int		len;

	if (number == 0)
		return (1);
	len = 0;
	while (number)
	{
		++len;
		number /= base;
	}
	return (len);
}

void		write_number_base(char *dst, size_t n, t_ull num, t_base base)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (num > 0)
		{
			*--dst = base.chars[(num % base.base)];
			num /= base.base;
		}
		else
			*--dst = '0';
		++i;
	}
}
