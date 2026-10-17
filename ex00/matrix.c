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

//	cicla su tutte le POSIZIONI della matrice 4x4 da 0 a 15

// per ogni posizione cicla tutti i NUMERI possibili da 1 a 4

// verifica che nella riga o nella colonna non sia già presente il numero
//		la verifica viene fatta su tutte le posizioni "inferiori" in riga o colonna
// se è presente procede col prossimo NUMERO
//		se ha terminato il ciclo sui numeri TORNA INDIETRO di UNA POSIZIONE cancellando l'ultimo numero impostato
// se non è presente procede con la prossima POSIZIONE

// quando finisce le posizioni arrivando a 15 la matrice è terminata

	return (0);
}
