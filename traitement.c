#include "header.h"

int 	traitement(char **tab, t_perso *pers)
{
	if (pers->vie > 0)
	{
		my_putstr("\33[2J");
		pers->vie--;
		if (pers->player_x > pers->sortie_x)
			pers->player_x = gauche(tab, pers);
		else if (pers->player_x < pers->sortie_x)
			pers->player_x = droite(tab, pers);
		else if (pers->player_y > pers->sortie_y)
			pers->player_y = haut(tab, pers);
		else
			pers->player_y = bas(tab, pers);
		aff(pers);
	}
	else
	{
		pers->vie = 0;
		my_putstr("KO \n");
		usleep(10000);
		return (1);
	}
	return (0);	
}

int 	traitement2(char **tab, t_perso *pers)
{
	recherche_target(pers);
	while (pers->player_x != pers->target_x || pers->player_y != pers->target_y)
	{
		if (pers->vie > 0)
		{		
			my_putstr("\33[2J");
			pers->vie--;
			if (pers->player_x > pers->target_x)
				pers->player_x = gauche(tab, pers);
			else if (pers->player_x < pers->target_x)
				pers->player_x = droite(tab, pers);
			else if (pers->player_y > pers->target_y)
				pers->player_y = haut(tab, pers);
			else 
			pers->player_y = bas(tab, pers);
			aff(pers);
		}
		else
			return (0);
	}
	if (pers->player_x == pers->target_x || pers->player_y == pers->target_y)
	{
		if (pers->vie > 0)
			traitement(tab, pers);
		else
			return (1);
	}
	return (0);
}

int		count_plus(char *tab, t_perso *pers)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '+')
			j++;
		i++;
	}
	pers->nb_ressource = j;
	return (pers->nb_ressource);
}

void	coord_plus(char **tab, t_perso *pers, char *buffer)
{
	int 	k;
	int 	c;

	c = 0;
	for (int i = 0; i < count_line_tab(buffer) - 1; i++)
	{
		for (int j = 0; j < count_colone_tab(buffer) - 1; j++)
		{
			if (tab[i][j] == '+')
			{
				k = 0;
				pers->c_r[c][k++] = j;
				pers->c_r[c][k++] = i;
				c++;
			}
		}	
	}
}

void 	recherche_target(t_perso *pers)
{
	t_cal	cal;
	int		px;
	int		sx;

	px = pers->player_x;
	sx = pers->sortie_x;
	cal.dist = abs(pers->c_r[0][0] - px) + abs(pers->c_r[0][1] - pers->player_y);
	cal.distr = abs(sx - pers->c_r[0][0]) + abs(pers->sortie_y - pers->c_r[0][1]);
	cal.fin = cal.dist + cal.distr;
	for (int i = 0; i < pers->nb_ressource; i++)
	{
		cal.dist1 = abs(pers->c_r[i][0] - px) + abs(pers->c_r[i][1] - pers->player_y);
		cal.distr1 = abs(sx - pers->c_r[i][0]) + abs(pers->sortie_y - pers->c_r[i][1]);
		cal.fin1 = cal.distr1 + cal.dist1;
		if (cal.fin1 < cal.fin)
		{
			cal.fin = cal.fin1;
			pers->target_x = pers->c_r[i][0];
			pers->target_y = pers->c_r[i][1];
			pers->c_r[i][0] = 100;
			pers->c_r[i][1]	= 100;
		}
	}
}