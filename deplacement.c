#include "header.h"

int 			haut(char **tab, t_perso *pers)
{
	if (tab[pers->player_y - 1][pers->player_x] == ' ')
	{
    tab[pers->player_y][pers->player_x] = ' ';
    pers->player_y--;
    tab[pers->player_y][pers->player_x] = '@';
  }
  else if (tab[pers->player_y - 1][pers->player_x] == '#')
 	{
      tab[pers->player_y][pers->player_x] = ' ';
      pers->player_y--;
 	    tab[pers->player_y][pers->player_x] = '@';
      my_putstr("       OK !\n");
  }
  else if (tab[pers->player_y - 1][pers->player_x] == '+')
  {
  		tab[pers->player_y][pers->player_x] = ' ';
		  pers->player_y--;
		  tab[pers->player_y][pers->player_x] = '@';
		  pers->vie = pers->vie + pers->ressource;
  }
  color_map(tab);
	return (pers->player_y);
}

int 			droite(char **tab, t_perso *pers)
{
	if (tab[pers->player_y][pers->player_x + 1] == ' ')
	{
		  tab[pers->player_y][pers->player_x] = ' ';
		  pers->player_x++;
		  tab[pers->player_y][pers->player_x] = '@';
  }
  else if (tab[pers->player_y][pers->player_x + 1] == '#')
  {
  		tab[pers->player_y][pers->player_x] = ' ';
  		pers->player_x++;
  		tab[pers->player_y][pers->player_x] = '@';
  		my_putstr("       OK ! \n");
  }
  else if (tab[pers->player_y][pers->player_x + 1] == '+')
  {
  		tab[pers->player_y][pers->player_x] = ' ';
		  pers->player_x++;
		  tab[pers->player_y][pers->player_x] = '@';
		  pers->vie = pers->vie + pers->ressource;
  }
  color_map(tab);
	return (pers->player_x);
}

int 			bas(char **tab, t_perso *pers)
{
	if (tab[pers->player_y + 1 ][pers->player_x] == ' ') 
	{
  		tab[pers->player_y][pers->player_x] = ' ';
		  pers->player_y++;
		  tab[pers->player_y][pers->player_x] = '@';
  }
  else if (tab[pers->player_y + 1][pers->player_x] == '#')
  {
  		tab[pers->player_y][pers->player_x] = ' ';
  		pers->player_y++;
  		tab[pers->player_y][pers->player_x] = '@';
  		my_putstr("       OK ! \n");
  }
  else if (tab[pers->player_y + 1][pers->player_x] == '+')
  {
  	  tab[pers->player_y][pers->player_x] = ' ';
		  pers->player_y++;
		  tab[pers->player_y][pers->player_x] = '@';
      pers->vie = pers->vie + pers->ressource;
  }
  color_map(tab);
  return (pers->player_y);
}

int 			gauche(char **tab, t_perso *pers)
{
	if (tab[pers->player_y][pers->player_x - 1] == ' ')
	{
  		tab[pers->player_y][pers->player_x] = ' ';
		  pers->player_x--;
		  tab[pers->player_y][pers->player_x] = '@';
  }
  else if (tab[pers->player_y][pers->player_x - 1] == '#')
  {
  		tab[pers->player_y][pers->player_x] = ' ';
  		pers->player_x--;
  		tab[pers->player_y][pers->player_x] = '@';
  		my_putstr("       OK !\n");
  }
  else if (tab[pers->player_y][pers->player_x - 1] == '+')
  {
  		tab[pers->player_y][pers->player_x] = ' ';
		  pers->player_x--;
		  tab[pers->player_y][pers->player_x] = '@';
		  pers->vie = pers->vie + pers->ressource;
  }
  color_map(tab);
	return (pers->player_x);
}

int  			moove(char **tab, t_perso *pers, char *buffer)
{
  int			col;
 	int			line;

 	col = count_colone_tab(buffer);
 	line = count_line_tab(buffer);
 	pers->sortie_x = sortie_x(tab, col, line);
	pers->sortie_y = sortie_y(tab, col, line);
	while (pers->player_x != pers->sortie_x || pers->player_y != pers->sortie_y)
	{
    trajet(pers);
		if ((pers->vie > 0) && (pers->distance <= pers->vie))
			traitement(tab, pers);
    else if ((pers->vie > 0) && (pers->distance > pers->vie))
      traitement2(tab, pers);
    else
		{
			my_putstr("\n       KO !\n");
			return (1);
		}
	}
	return (0);
}