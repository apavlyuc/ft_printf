/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:46:39 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/08/24 23:28:58 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>

# define NO_PRECISION (-1)

typedef unsigned long long	t_ull;
typedef long long			t_ll;

typedef union				u_data
{
	t_ull					ull;
	t_ll					ll;
}							t_data;

typedef struct				s_base
{
	int						base;
	char const				*chars;
}							t_base;

typedef struct				s_flags
{
	char					minus;
	char					plus;
	char					space;
	char					hash;
	char					zero;
}							t_flags;

typedef struct				s_specificator
{
	char					h;
	char					hh;
	char					l;
	char					ll;
	char					j;
	char					z;
}							t_specificator;

typedef struct				s_param
{
	t_flags					flags;
	long int				width;
	long int				accuracy;
	t_specificator			specificator;
	char					type;
	t_data					data;
}							t_param;

int							ft_printf(const char *str, ...);

int							print_text(const char **str);

int							print_param(const char **str, va_list *args);
int							create_param(char **dst, va_list *args,
							t_param *param);

int							update_param(const char **str, va_list *args,
							t_param *p);

void						read_flags(const char **str, t_param *param);
void						read_width(const char **str, va_list *args,
							t_param *param);
void						read_accuracy(const char **str, va_list *args,
							t_param *p);
void						read_specificator(const char **str, t_param *param);
int							read_type(const char **str, t_param *param);

int							handle_s(char **dst, va_list *args, t_param *param);
int							handle_ls(char **dst, va_list *args,
							t_param *param);
int							handle_c(char **dst, va_list *args, t_param *param);
int							handle_lc(char **dst, va_list *args,
							t_param *param);
int							handle_d(char **dst, va_list *args, t_param *param);
int							handle_o(char **dst, va_list *args, t_param *param);
int							handle_u(char **dst, va_list *args, t_param *param);
int							handle_x(char **dst, va_list *args, t_param *param);
int							handle_x_fill(char **dst, char const *tab,
							t_param *param);
int							handle_other(char **dst, va_list *args,
							t_param *param);

void						get_unsigned_arg(va_list *args, t_param *param);
int							get_length(const char *string);
int							get_wlength(const wchar_t *wstring);
int							get_symbols_count(const wchar_t *string,
							int accuracy);
int							get_bytes_in_wstr(const wchar_t *wstring,
							int count);
int							get_text_len(const char *string);
int							get_number_len(long long int number);
int							get_number_base_len(t_ull number, int base);
void						fill(char *dst, char c, int len);
void						wchar_to_char(char **dst, wchar_t *src,
							int lp, int ls);
void						init_param(t_param *param);
void						write_number_base(char *dst, size_t n,
							t_ull num, t_base base);

#endif
