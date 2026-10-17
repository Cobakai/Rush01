#include <unistd.h>

void	ft_print_matrix(int m[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = '0' + m[i][j];
			write (1, &c, 1);
			if (j < 3)
				write (1, " " , 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	int matrix[4][4] = {
		{1, 2, 3, 4},
		{4, 1, 2, 3},
		{3, 4, 1, 2},
		{2, 3, 4, 1}
	};

	ft_print_matrix(matrix);
	return (0);
}
