#include <cstdlib>

#include "ft_printf.h"

int			main(int ac, char **av)
{
	int		ret1 = 0;
	int		ret2 = 0;

	ret1 = ft_printf("%s", "kyrva");
	ret2 = printf("%ls\n", "kyrva");
	cout << "my ret = " << (ret1 + 1) << endl;
	cout << "of ret = " << ret2 << endl;

	system("pause");
	return 0;
}