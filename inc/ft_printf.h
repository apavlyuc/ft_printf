/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <apavlyuc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:46:39 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/07/14 15:45:35 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdarg.h>
#include <wchar.h>

typedef struct s_flags
{
	char	minus;
	char	plus;
	char	space;
	char	hash;
	char	zero;
} t_flags;

typedef struct s_width
{
	int		width;
	char	asterisk;
} t_width;

typedef struct s_accuracy
{
	int		accuracy;
	char	asterisk;
} t_accuracy;

typedef struct s_specificator
{
	char h;
	char hh;
	char l;
	char ll;
	char j;
	char z;
} t_specificator;

typedef struct s_param
{
	t_flags			flags;
	t_width			width;
	t_accuracy		accuracy;
	t_specificator	specificator;
	char			type;
} t_param;

int			ft_printf(const char *string, ...);

//	print data
int			print_text(const char **string);

int			print_param(const char **string, va_list *args);
int			parse_param(const char **string, va_list *args, t_param *param);
int			create_param(char **dst, va_list *args, t_param *param);

//	init @param with actual info
int			update_param(const char **string, va_list *args, t_param *param);

int			read_flags(const char **string, t_param *param);
int			read_width(const char **string, va_list *args, t_param *param);
int			read_accuracy(const char **string, va_list *args, t_param *param);
int			read_specificator(const char **string, t_param *param);
int			read_type(const char **string, t_param *param);

//	handlers
int			handle_s(char **dst, va_list *args, t_param *param);
int			handle_ls(char **dst, va_list *args, t_param *param);


//	helpers
int			get_length(const char *string); // len from current position to '\0'
int			get_text_len(const char *string); // len from current position to '%'
int			get_number_len(long long int number);
void		fill(char *dst, char c, int len);
void		init_param(t_param *param);

#endif // !FT_PRINTF
