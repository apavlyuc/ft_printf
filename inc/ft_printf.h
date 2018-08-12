/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:46:39 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/12 21:12:57 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>

typedef struct		s_flags
{
	char			minus;
	char			plus;
	char			space;
	char			hash;
	char			zero;
}					t_flags;

typedef struct		s_width
{
	int				width;
	char			asterisk;
}					t_width;

typedef struct		s_accuracy
{
	int				accuracy;
	char			asterisk;
}					t_accuracy;

typedef struct		s_specificator
{
	char			h;
	char			hh;
	char			l;
	char			ll;
	char			j;
	char			z;
}					t_specificator;

typedef struct		s_param
{
	t_flags			flags;
	t_width			width;
	t_accuracy		accuracy;
	t_specificator	specificator;
	char			type;
}					t_param;

int					ft_printf(const char *str, ...);

int					print_text(const char **str);

int					print_param(const char **str, va_list *args);
int					parse_param(const char **str, va_list *args, t_param *p);
int					create_param(char **dst, va_list *args, t_param *param);

int					update_param(const char **str, va_list *args, t_param *p);

int					read_flags(const char **str, t_param *param);
int					read_width(const char **str, va_list *args, t_param *param);
int					read_accuracy(const char **str, va_list *args, t_param *p);
int					read_specificator(const char **str, t_param *param);
int					read_type(const char **str, t_param *param);

int					handle_s(char **dst, va_list *args, t_param *param);
int					handle_ls(char **dst, va_list *args, t_param *param);
int					handle_c(char **dst, va_list *args, t_param *param);
int					handle_lc(char **dst, va_list *args, t_param *param);
int					handle_d(char **dst, va_list *args, t_param *param);
int					handle_o(char **dst, va_list *args, t_param *param);
int					handle_u(char **dst, va_list *args, t_param *param);
int					handle_x(char **dst, va_list *args, t_param *param);

int					get_length(const char *string);
int					get_wlength(const wchar_t *wstring);
int					get_symbols_count(const wchar_t *string, int accuracy);
int					get_bytes_in_wstr(const wchar_t *wstring, int count);
int					get_text_len(const char *string);
int					get_number_len(long long int number);
void				fill(char *dst, char c, int len);
void				wchar_to_char(char **dst, wchar_t *src, int lp, int ls);
void				init_param(t_param *param);

#endif
