#ifndef MES_FONCTIONS_H_
#define MES_FONCTIONS_H_

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define LINE 11
#define COL 18
#define TAILLE 210

typedef struct perso
{
	int		vie;
	int		col;
	int		line;
	int		player_x;
	int		player_y;
	int		ressource;
	int		nb_ressource;
	int		c_r[50][2];
	int		target_x;
	int		target_y;
	int		sortie_x;
	int		sortie_y;
	int		distance;
	int		stop;
}			t_perso;

typedef struct cal
{
	int		dist;
	int		distr;
	int		dist1;
	int		distr1;
	int		fin;
	int		fin1;
}			t_cal;

void		my_putchar(char c);
void		my_putstr(char *str);
int			my_getnbr(char *str);
int			digit(char caractere);
void		my_putnbr(int n);
int			is_number(char *str);
int			check_args(int argc, char* argv[]);
int			open_map(char* argv[],t_perso *pers);
int			my_strcmp(char s1, char s2);
void		color_element(char	element);
void		color_map(char **tab);
char		**tab_double(char buffer[TAILLE]);
int			count_colone_tab(char *tab);
int			count_line_tab(char *tab);
int			taille_tab(char *tab, t_perso *pers);
int			player_x(char **tab, int col, int line);
int			player_y(char **tab, int col, int line);
int			sortie_x(char **tab, int col, int line);
int			sortie_y(char **tab, int col, int line);
int			haut(char **tab, t_perso *pers);
int			droite(char **tab, t_perso *pers);
int			bas(char **tab, t_perso *pers);
int			gauche(char **tab, t_perso *pers);
int 		moove(char **tab, t_perso *pers, char *buffer);
t_perso		*init_stucture(char* argv[]);
int			my_getnbr(char *str);
int			traitement(char **tab, t_perso *pers);
int			count_plus(char *tab, t_perso *pers);
void 		coord_plus(char **tab, t_perso *pers, char *buffer);
int			trajet(t_perso *pers);
int			abs(int num);
void		recherche_target(t_perso *pers);
int			traitement2(char **tab, t_perso *pers);
void		aff(t_perso *pers);
void		pos_joueur(char **tab, t_perso *pers);

#endif