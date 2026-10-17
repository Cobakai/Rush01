#include <stdio.h>

int	ft_check_input(int view[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if(view[i] < 1 || view[i] > 4)
			return (0);
		i++;
	}
	return (1);
}