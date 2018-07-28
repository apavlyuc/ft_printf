/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:30:15 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/28 17:52:26 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdlib.h>

int     handle_lc(char **dst, va_list *args, t_param *param)
{
    *dst = (char *)malloc(1);
    (void)dst;
    (void)args;
    (void)param;
    return (0);
}
