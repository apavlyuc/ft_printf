/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:11:14 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/28 18:29:11 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdlib.h>

static int          get_param_c_len(t_param *param, int *spaces)
{
    int             ret;

    *spaces = param->width.width > 1 ? (param->width.width - 1) : 0;
    ret = *spaces + 1;
    return (ret);
}

static void         insert(char *dst, unsigned char src, int spaces)
{
    *(dst + spaces) = src;
}

static void         rinsert(char *dst, unsigned char src)
{
    *dst = src;
}

int                 handle_c(char **dst, va_list *args, t_param *param)
{
    unsigned char   c;
    int             spaces;
    int             len;

    if (param->specificator.l == 1)
        return handle_lc(dst, args, param);
    c = (unsigned char)va_arg(*args, int);
    len = get_param_c_len(param, &spaces);
    *dst = (char *)malloc(sizeof(char) * (len + 1));
    fill(*dst, ' ', len);
    if (param->flags.minus == 0)
        insert(*dst, c, spaces);
    else
        rinsert(*dst, c);
    *(*dst + len) = '\0';
    return (len);
}
