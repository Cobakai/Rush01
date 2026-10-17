// verifica che le coppie di viste dell'input siano ammissibili
// sono matematicamente escluse le coppie:
// (1,1); (3,3); (4,4); (2,4); e (4,2); (3,4); e (4,3);
int ft_check_allowed_views(int v[16])
{
	int	i;

// verifica le coppie di viste per le colonne
	i = 0;
	while (i < 4)
	{
		if (v[i] == 1 && v[i+4] == 1)
			return (0);
		if (v[i] == 3 && v[i+4] == 3)
			return (0);
		if (v[i] == 4 && v[i+4] == 4)
			return (0);
		if ((v[i] == 2 && v[i+4] == 4) || (v[i] == 4 && v[i+4] == 2))
			return (0);
		if ((v[i] == 3 && v[i+4] == 4) || (v[i] == 4 && v[i+4] == 3))
			return (0);
		i++;
	}
// verifica le coppie di viste per le righe
	i = 8;
	while (i < 4)
	{
		if (v[i] == 1 && v[i+4] == 1)
			return (0);
		if (v[i] == 3 && v[i+4] == 3)
			return (0);
		if (v[i] == 4 && v[i+4] == 4)
			return (0);
		if ((v[i] == 2 && v[i+4] == 4) || (v[i] == 4 && v[i+4] == 2))
			return (0);
		if ((v[i] == 3 && v[i+4] == 4) || (v[i] == 4 && v[i+4] == 3))
			return (0);
		i++;
	}
	return (1);
}