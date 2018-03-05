#include "header.h"

void	aff(t_perso *pers)
{
	my_putstr("\npoint de vie --> ");
	my_putnbr(pers->vie);
	my_putstr("\n");
	usleep(300000);
	my_putstr("\e[0m");
}

void 	pos_joueur(char **tab, t_perso *pers)
{
	for (int i = 0; i < COL; i++)
	{
		for(int j = 0; j < LINE; j++)
		{
			if (tab[i][j] == '@')
			{
				pers->player_x = j;
				pers->player_y = i;				
			}
		}
	}
}