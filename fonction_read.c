#include "header.h"

int		open_map(char* argv[],t_perso *pers)
{
	int		file;
	int		resRead;
	char	buffer[TAILLE];
	char 	**tab;

	tab = NULL;
	resRead = 0;
	file = open(argv[3], O_RDONLY, 0);
	resRead = read(file, (char*)buffer, TAILLE);
	while (resRead > 0)
		resRead = read(file, (char*)buffer, sizeof(buffer));
	taille_tab(buffer, pers);
	return (0);
}