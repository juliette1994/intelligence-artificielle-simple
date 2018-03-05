#include "header.h"

int		sortie_x(char **tab, int col, int line)
{
	int		x_sortie;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < line && j <= col)
	{
		if (tab[i][j] == '#')
			x_sortie = j;
		if (j == col)
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (x_sortie);
}

int		sortie_y(char **tab, int col, int line)
{
	int		i;
	int		j;
	int		y_sortie;

	i = 0;
	j = 0;
	while (i < line && j <= col)
	{
		if (tab[i][j] == '#')
			y_sortie = i;
		if (j == col)
		{
			i++;
			j = 0;
		}
		j++;
	}
	my_putstr("\n");
	return (y_sortie);
}