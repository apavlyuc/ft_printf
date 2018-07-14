#include "ft_printf.h"
#include <cstdlib>

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
				return (tmp_ret);
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
	{
		int i = 0;
		while (i < len)
		{
			std::cout << *(*string + i++);
		}
	}
	*string += len;
	return (len);
}

int			print_param(const char **string, va_list *args)
{
	int		ret;
	char	*dst;
	t_param	param;

	ret = parse_param(string, args, &param);
	if (ret == 1)
		return (1);
	if (ret < 0)
		return (-1);
	ret = create_param(&dst, args, &param);
	cout << dst << endl; // delete
	free(dst);
	return (ret);
}

int			parse_param(const char **string, va_list *args, t_param *param)
{
	int ret;

	if (**string == '%')
	{
		std::cout << '%';
		++(*string);
		return (1);
	}
	ret = update_param(string, args, param);
	return (ret);
}