void    store_dict(char ***dict, int newline_count)
{
    int i;
    int j;
    
    dict = malloc(newline_count * sizeof(char **));
    if (dict == NULL)
    {
        write(1, "Error in memory allocation\n", 27);
        return ;
    }
    i = 0;
    while (i < newline_count)
    {
        dict[i] = malloc(2 * sizeof(char *));
        if (dict[i] == NULL)
        {
            write(1, "Error in memory allocation\n", 27);
            return ;
        }
        j = 0;
        while (j < 2)
        {
            dict[i][j] = malloc(20 * sizeof(char));
            if (dict[i][j] == NULL)
            {
                write(1, "Error in memory allocation\n", 27);
                return ;
            }
            j++;
        }
        i++;
    }
}