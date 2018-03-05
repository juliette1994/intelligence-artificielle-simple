#include "header.h"

int		count_colone_tab(char *tab)
{
	int		i;

	i = 0;
	while (tab[i] != '\n')
	{
		i++;
	}
	return (i);
}

int		count_line_tab(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int 	taille_tab(char *buffer, t_perso *pers)
{
 	int		col;
 	int		line;
 	char	**tab;

 	col = count_colone_tab(buffer);
 	line = count_line_tab(buffer);
 	pers->col = col;
 	pers->line = line;
 	my_putnbr(pers->col);
 	count_plus(buffer, pers);
	tab = tab_double(buffer);
	coord_plus(tab, pers, buffer);
	color_map(tab);
	pers->player_x = player_x(tab, col, line);
	pers->player_y = player_y(tab, col, line);
	pers->sortie_x = sortie_x(tab, col, line);
	pers->sortie_y = sortie_y(tab, col, line);
	trajet(pers);
	moove(tab, pers, buffer);
	free(tab);
	return (0);
}

int 	player_x(char **tab, int col, int line)
{
	int		x_joueur;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < line && j <= col)
	{
		if (tab[i][j] == '@')
			x_joueur = j;
		if (j == col)
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (x_joueur);
}

int		player_y(char **tab, int col, int line)
{
	int		i;
	int		j;
	int		y_joueur;

	i = 0;
	j = 0;
	while (i < line && j <= col)
	{
		if (tab[i][j] == '@')
			y_joueur = i;
		if (j == col)
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (y_joueur);
}