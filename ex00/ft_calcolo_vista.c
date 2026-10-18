void ft_calcolo_vista(int matrix[4][4], int (*view)[16])
{
    int i;//seleziona la riga o la colonna da analiazzare
    int j;//scorre le celle
    int max;//memorizza il valore massimo
    int count;//conta i valorri visibili

    i = 0;
    while (i < 4)
    {
        max = 0;
        count = 0;
        j = 0;
        while (j < 4)
        {
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
                count++;
            }
            j++;
        }
        (*view)[8 + i] = count;
        i++;
    }
}