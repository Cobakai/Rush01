int ft_check_views(int v1[16], int v2[16])
{
    int	i;

	i = 0;
	while (i < 16)
	{
		if (v1[i] != v2[i])
			return (0);
		i++;
	}
	return (1);
}