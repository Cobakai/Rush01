#include <unistd.h>
#include <stdio.h>

int	ft_convert_view_from_string(char *s, int v[16])
{
	char	*ptr;
	int		i;

	ptr = s;
	i = 0;
	while (*ptr)
	{
		if (*ptr >= '0' && *ptr <= '9')
		{
			v[i] = *ptr - '0';
			i++;
			ptr++;
		}
		while(*ptr == ' ')
			ptr++;
	}
	if (i != 16)
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int view[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int	i;

	if (argc != 2) 
	{
		write (1, "ERRORE\n", 7);
		return (0);
	}
	if (ft_convert_view_from_string(argv[1], view) == 0 )
	{
		write (1, "ERRORE\n", 7);
		return (0);
	}
	i = 0;
	printf("( ");
	while (i < 16)
	{
		printf ("%d, ", view[i]);
		i++;
	}
	printf(")\n");
	return (0);
}