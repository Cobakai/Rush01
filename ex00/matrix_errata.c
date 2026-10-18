#include <unistd.h>
#include <stdio.h>

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

int	ft_check_avail_num(int n, int m[4][4], int p)
{
	int	i;
	int	j;
	int k;

	i = x_from_pos(p, 4);
	j = y_from_pos(p, 4);
	k = 0;
	while (k < i)
	{
		if (m[k][j] == n)
			return (0);
		k++;
	}
	k = 0;
	while (k < j)
	{
		if (m[i][k] == n)
			return (0);
		k++;
	}
	return (1);
}

int	main(void)
{
	int	i;
	int	j;
	int	p;
	int num;
	int fl_num_ok;
//	int num_trace[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int matrix[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	ft_print_matrix(matrix);
	write(1, "---------\n", 10);

/*// Inizializza la matrice a 0
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
*/

//	cicla su tutte le POSIZIONI della matrice 4x4 da 0 a 15
	p = 0;
	while (p < 16 && p >= 0)
	{
		printf("ciclo p, valore: %d \n", p);
		ft_print_matrix(matrix);
		write (1, "---------\n", 10);

		i = x_from_pos(p, 4);
		j = y_from_pos(p, 4);
// per ogni posizione cicla tutti i NUMERI possibili da 1 a 4
		num = matrix[x_from_pos(p, 4)][y_from_pos(p, 4)] + 1;
		fl_num_ok = 0;
		while (num <= 4)
		{
			printf("ciclo num, valore: %d \n", num);


// verifica che nella riga o nella colonna non sia già presente il numero
//		la verifica viene fatta su tutte le posizioni "inferiori" in riga o colonna
			if (ft_check_avail_num(num, matrix, p))
				{
					matrix[i][j] = num;
					printf("posizione: %d, numero: %d\n", p, num);
					num = 5;
					fl_num_ok = 1;
				}
			else
				{
					fl_num_ok = 0;
					num++;
				}
		}
//		se ha terminato il ciclo sui numeri e nessuno è disponibile 
// 		allora TORNA INDIETRO di UNA POSIZIONE cancellando l'ultimo numero impostato sulla matrice
		if (fl_num_ok == 0)
		{
			p--;
			matrix[x_from_pos(p, 4)][y_from_pos(p, 4)] = 0;
		}
// 		se il numero è disponibile e la matrice è stata aggiornata 
// 		allora procede con la prossima POSIZIONE
		else 
		{
			p++;
		}
// 		quando finisce le posizioni arrivando a 15 la matrice è terminata e la stampa
		if (p == 16)
		{
			ft_print_matrix(matrix);
			write (1, "---------\n", 10);
			p--;
			while (((p % 4 == 0) && matrix[x_from_pos(p, 4)][y_from_pos(p, 4)] == 4)  ||
				(matrix[x_from_pos(p, 4)][y_from_pos(p, 4)] < matrix[x_from_pos(p - 1, 4)][y_from_pos(p - 1, 4)]))
			{   
				matrix[x_from_pos(p, 4)][y_from_pos(p, 4)] = 0;
				p--;
				printf("p - %d\n", p);
			}
		}
	}

	return (0);
}
