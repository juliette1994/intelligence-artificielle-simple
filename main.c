#include "header.h"

int		main(int argc, char* argv[])
{
	t_perso		*pers;		
	
	if (check_args(argc, argv) == 0){
	pers = init_stucture(argv);
	open_map(argv, pers);
	my_putstr("\n");
	}
	return (0);
}

int		check_args(int argc, char* argv[])
{
	int 	ok;

	ok = 1;
	if (argc != 4)
		my_putstr("nombre d'arguments incorrect \n");
	else
	{
		if ((is_number(argv[1]) == 1) || (is_number(argv[2]) == 1))
			my_putstr("Erreur les Deux premiers arguments doivent etre des nombres positifs\n");
		else if (is_number(argv[3]) == 1 && (open(argv[3], O_RDONLY, 0) == -1))
			my_putstr("La map entrée est soit vide, soit n'existe pas. \n");
		else
			ok = 0;
	}
	return (ok);
}

t_perso		*init_stucture(char* argv[])
{
	t_perso		*pers;

	pers = malloc(sizeof(struct perso));
	pers->vie = my_getnbr(argv[1]);
	pers->player_x = 0;
	pers->player_y = 0;
	pers->nb_ressource = 0;
	pers->ressource = my_getnbr(argv[2]);
	pers->sortie_x = 0;
	pers->sortie_y = 0;
	return (pers);
}