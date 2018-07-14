/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:43:26 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/14 15:56:07 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/ft_printf.h"

int			main(int ac, char **av)
{
	int		ret1;
	int		ret2;

	(void)ac;
	(void)av;
	ret1 = ft_printf("%s\n", "kyrva");
	ret2 = printf("%s\n", "kyrva");
	printf("my ret = %d\nof ret = %d\n", ret1, ret2);
	return (0);
}
