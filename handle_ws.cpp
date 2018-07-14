#include <cstdlib>
#include <sys/types.h>
#include "ft_printf.h"

int			handle_S(char **dst, va_list *args, t_param *param)
{
	wchar_t	*string;
	int		len;

	string = va_arg(*args, wchar_t*);
	string = string == NULL ? (wchar_t *)L"(null)" : string;

	return (0);
}