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

// conversione da coordinate a punto posizione
// p va da 0 a dim * dim
int	pos_from_coord(int x, int y, int dim)
{
	int	p;

	p = x * dim + y;
	return (p);
}

// conversione da punto posizione a coordinata x
int x_from_pos(int p, int dim)
{
	int	x;
	
	x = p / dim;
	return (x);
}

// conversione da punto posizione a coordinata y
int y_from_pos(int p, int dim)
{
	int	y;
	
	y = p % dim; 
	return (y);
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
