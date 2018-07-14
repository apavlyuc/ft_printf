#include <cstdlib>

#include "ft_printf.h"

int			create_param(char **dst, va_list *args, t_param *param)
{
	int		ret;

	if (param->type == 's')
		ret = handle_s(dst, args, param);

	return (ret);
}

